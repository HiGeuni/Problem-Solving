import sys
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline

def getParent(ls, x):
    if ls[x] == x:
        return ls[x]
    ls[x] = getParent(ls, ls[x])
    return ls[x]

def unionParent(ls, a, b):
    a = getParent(ls, a)
    b = getParent(ls, b)
    if a > b:
        ls[a] = b
    else:
        ls[b] = a

def findParent(ls, a, b):
    a = getParent(ls, a)
    b = getParent(ls, b)
    if a == b:
        return True
    else:
        return False

p,w = map(int,input().split())
parent = [i for i in range(p)]
c,v = map(int,input().split())
h = []
for i in range(w):
    ta, tb, tc = map(int,input().split())
    heappush(h, [-tc, ta, tb])

ans = 0
while h:
    weight, s, e = heappop(h)
    weight *= -1
    unionParent(parent, s, e)
    if findParent(parent, c, v):
        ans=weight
        break
print(ans)
