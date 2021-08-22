import math
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def init(s, e, node):
    if s == e:
        tree[node] = ls[s]
    else:
        mid = (s+e)//2
        tree[node] = init(s, mid, 2*node) + init(mid+1, e, 2*node+1)
    return tree[node]

def sum_(s, e, node, l, r):
    if l>e or r<s: return 0
    if l<=s and e<=r:
        return tree[node]
    mid = (s+e)//2
    return sum_(s, mid, 2*node, l, r) + sum_(mid +1, e, 2*node + 1, l, r)

def update(s, e, node, idx, dif):
    if idx<s or idx > e: return
    tree[node] += dif
    if s == e : return
    mid = (s+e)//2
    update(s, mid, 2*node, idx, dif)
    update(mid+1, e, 2*node+1, idx, dif)



n = int(input())
ls = list(map(int,input().split()))
tree = [0 for _ in range(4*n)]
q = int(input())

oneCnt = 0
twoCnt = 0

oneQ = []
twoQ = []

for i in range(q):
    tmp = list(map(int,input().split()))
    if tmp[0] == 2:
        twoQ.append([twoCnt] + tmp)
        twoCnt+=1
    else:
        oneQ.append(tmp)
        oneCnt+=1

twoQ = sorted(twoQ, key=lambda x:x[2])
oneIdx = 0
twoIdx = 0

answer = [0 for _ in range(twoCnt)]
init(0, n-1, 1)

while twoIdx != twoCnt:
    base = twoQ[twoIdx][2]
    if base > oneIdx:
        diff = oneQ[oneIdx][2] - ls[oneQ[oneIdx][1]-1]
        ls[oneQ[oneIdx][1]-1] = oneQ[oneIdx][2]
        update(0, n-1, 1, oneQ[oneIdx][1]-1, diff)
        oneIdx += 1
    else:
        tmp = sum_(0, n-1, 1, twoQ[twoIdx][3]-1, twoQ[twoIdx][4]-1)
        answer[twoQ[twoIdx][0]] = tmp
        twoIdx += 1

for i in answer:
    print(i)
