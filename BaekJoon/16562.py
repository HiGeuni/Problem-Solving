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

n,m,k = map(int,input().split())
cost = list(map(int,input().split()))
graph = [[] for _ in range(n+1)]
parent = [i for i in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    if not findParent(parent, a, b):
        unionParent(parent, a, b)

ans = [float('inf') for _ in range(n+1)]
for i in range(1, n+1):
    tmp = getParent(parent, i)
    ans[tmp] = min(ans[tmp], cost[i-1])
res = 0
for i in range(1, n+1):
    if ans[i]!=float('inf'):
        res += ans[i]
print(res if res <= k else "Oh no")