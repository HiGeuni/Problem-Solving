import sys
from heapq import heappush, heappop
input = sys.stdin.readline

def get_parent(t):
    if parents[t] == t:
        return t
    parents[t] = get_parent(parents[t])
    return parents[t]

def union_family(a,b):
    ta = get_parent(a)
    tb = get_parent(b)
    if ta > tb:
        parents[ta] = tb
    else:
        parents[tb] = ta



n = int(input())
edges = []
for i in range(1, n+1):
    tmp = int(input())
    heappush(edges, [tmp, 0, i])

for i in range(1, n+1):
    tmp = list(map(int,input().split()))
    for j in range(1, n+1):
        heappush(edges, [tmp[j-1], i, j])
parents = [i for i in range(n+1)]

ans = 0
while edges:
    cost, start, end = heappop(edges)
    if get_parent(start) != get_parent(end):
        union_family(start, end)
        ans += cost

print(ans)