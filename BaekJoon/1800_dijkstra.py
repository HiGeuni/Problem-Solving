import sys
from heapq import heappush, heappop
input = sys.stdin.readline

# def dijkstra(lim):
#     h = []
#     dist = [float('inf') for _ in range(N + 1)]
#     dist[1] = 0
#     heappush(h, [0, 1, 0])
#     while h:
#         cost, curNode, limit = heappop(h)
#         for it in graph[curNode]:
#             if graph[curNode][it] < dist[it]:
#                 if limit >= K:
#                     if graph[curNode][it] > lim:
#                         continue
#                     else:
#                         dist[it] = graph[curNode][it]
#                         heappush(h, [dist[it], it, limit])
#                 else:
#                     dist[it] = graph[curNode][it]
#                     if graph[curNode][it] > lim:
#                         heappush(h, [dist[it], it, limit+1])
#                     else:
#                         heappush(h, [dist[it], it, limit])
#     return dist[N]

def dijkstra(lim):
    h = []
    dist = [float('inf') for _ in range(N + 1)]
    dist[1] = 0
    heappush(h, [0, 1])
    while h:
        cost, curNode= heappop(h)
        if dist[curNode] < cost:
            continue
        for it in graph[curNode]:
            if graph[curNode][it] > lim:
                if cost + 1 < dist[it]:
                    dist[it] = cost + 1
                    heappush(h, [dist[it], it])
            else:
                if cost < dist[it]:
                    dist[it] = cost
                    heappush(h, [dist[it], it])
    return dist[N]

N, P, K = map(int,input().split())
graph = [dict() for _ in range(N+1)]
for _ in range(P):
    u, v, w = map(int,input().split())
    graph[u][v] = w
    graph[v][u] = w

ans = -1
l = 0
r = 10000001
while l<=r:
    mid = (l+r) // 2
    if dijkstra(mid) <= K:
        ans = mid
        r = mid -1
    else:
        l = mid +1

print(ans)
