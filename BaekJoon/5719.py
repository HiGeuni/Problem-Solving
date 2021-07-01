import sys
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline

def dijkstra(start, end):
    h = []
    heappush(h, [0, start])
    dist[start] = 0
    while h:
        cost, cur = heappop(h)
        if dist[cur] < cost:
            continue
        for i in graph[cur]:
            cost2 = cost + graph[cur][i]
            if cost2 < dist[i]:  # 해당 지점을 거치는 것이 거리가 짧은 경우
                dist[i] = cost2
                heappush(h, (cost2, i))
    return dist[end]

def bfs():
    dq = deque()
    dq.append(dst)
    while dq:
        cur = dq.popleft()
        if cur == src:
            continue
        for (prevVertex, pervCost) in reverseGraph[cur]:
            if dist[cur] == dist[prevVertex] + graph[prevVertex][cur]:
                if (prevVertex, cur) not in removeList:
                    removeList.append((prevVertex, cur))
                    dq.append(prevVertex)


while True:
    N,M = map(int,input().split())
    if N == 0 and M == 0:
        break
    src, dst = map(int,input().split())
    graph = [dict() for _ in range(N)]
    reverseGraph = [[] for _ in range(N)]
    removeList = []

    for i in range(M):
        u, v, w = map(int,input().split())
        graph[u][v] = w
        reverseGraph[v].append([u, w])
    dist = [2e9 for _ in range(N)]
    dijkstra(src, dst)
    bfs()
    for u, v in removeList:
        del graph[u][v]
    dist = [2e9 for _ in range(N)]
    ans = dijkstra(src, dst)
    print(ans if ans != 2e9 else -1)

