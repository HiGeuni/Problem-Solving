import sys
import math
input = sys.stdin.readline

mod = 1000000007

def proInit(node, start, end):
    if start == end:
        tree[node] = ls[start] % mod
    else:
        proInit(2*node, start, (start+end)//2)
        proInit(2*node+1, (start+end)//2+1, end)
        tree[node] = (tree[node*2] * tree[node*2+1]) % mod

def update(node, start, end, idx,  val):
    if idx < start or idx > end :
        return
    if start == end:
        tree[node] = val
        return tree[node]
    mid = (start+end) //2
    update(2*node, start, mid, idx, val)
    update(2 * node + 1, mid + 1, end, idx, val)
    tree[node] = tree[2*node] *  tree[2*node+1] % mod
    return tree[node]

def proVal(node, start, end, src, dst):
    if src > end or dst < start:
        return 1
    if src <= start and end <= dst:
        return tree[node]
    mid = (start + end)//2
    return  proVal(2*node, start, mid, src, dst) * proVal(2*node+1, mid+1, end, src, dst) % mod

n,m, q = map(int,input().split())
ls = [int(input()) for _ in range(n)]

height = int(math.ceil(math.log2(n)))
size = (1 << (height + 1))

tree = [ 0 for _ in range(size+10)]

proInit(1, 0, n-1)

for _ in range(m+q):
    a,b, c = map(int,input().split())
    if a == 1:
        update(1, 0, n-1, b-1, c)
    else:
        print(proVal(1, 0, n-1, b-1, c-1))
