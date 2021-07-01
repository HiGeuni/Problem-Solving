import sys
from heapq import heappush, heappop
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


N, M, K = map(int,input().split())

parent = [i for i in range(N+1)]

plant = list(map(int,input().split()))
edges = []
for i in range(M):
    u, v, w = map(int,input().split())
    edges.append([w, u, v])
edges.sort()
for i in range(len(plant) - 1):
    unionParent(parent, plant[i], plant[i+1])

ans = 0
for cost, from_, to_ in edges:
    if not findParent(parent, from_, to_):
        unionParent(parent, from_, to_)
        ans += cost

print(ans)
