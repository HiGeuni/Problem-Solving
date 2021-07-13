import sys
from heapq import heappush, heappop
input = sys.stdin.readline

def find_parent(n):
    if parent[n] == n:
        return parent[n]
    parent[n] = find_parent(parent[n])
    return parent[n]

def union_parent(n, m):
    pN = find_parent(n)
    pM = find_parent(m)
    if pN < pM:
        parent[pM] = pN
    else:
        parent[pN] = pM

N,M = map(int,input().split())
edges = []
for _ in range(M):
    u, v, w  = map(int,input().split())
    heappush(edges,[w, u, v])
parent = [i for i in range(N+1)]

res = 0
last = 0
while edges:
    w, u, v = heappop(edges)
    if find_parent(u) != find_parent(v):
        union_parent(u, v)
        res += w
        last = w
print(res-last)