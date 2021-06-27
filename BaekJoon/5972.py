import sys
from heapq import heappush, heappop
input = sys.stdin.readline

def dijkstra():
    h = []
    visit = [2e9 for _ in range(n+1)]
    visit[1] = 0
    heappush(h, [0,1])
    while h:
        curCost, cur = heappop(h)
        if visit[cur] < curCost:
            continue
        for nxt, cost in graph[cur]:
            if visit[nxt] > curCost + cost:
                visit[nxt] = curCost + cost
                heappush(h, [visit[nxt], nxt])
    return visit[n]



n,m = map(int,input().split())

graph = [[] for _ in range(n+1)]

for i in range(m):
    fr, to, weight = map(int,input().split())
    graph[fr].append([to, weight])
    graph[to].append([fr, weight])

print(dijkstra())