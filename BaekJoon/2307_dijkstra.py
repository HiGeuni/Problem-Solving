import sys
from collections import deque
from heapq import heappush, heappop

input = sys.stdin.readline

def dijkstra(start, end):
    h = []
    heappush(h, [0, start])
    dist[start] = 0
    while h:
        cost, cur = heappop(h)
        if dist[cur] < cost:
            continue
        for it in graph[cur]:
            if not flag[cur][it] or not flag[it][cur] :
                continue
            cost2 = cost + graph[cur][it]
            if cost2 < dist[it]:  # 해당 지점을 거치는 것이 거리가 짧은 경우
                dist[it] = cost2
                heappush(h, (cost2, it))
    return dist[end]


def bfs():
    dq = deque()
    dq.append(n)
    while dq:
        cur = dq.popleft()
        if cur == 1:
            continue
        for (prevVertex, pervCost) in reverseGraph[cur]:
            if dist[cur] == dist[prevVertex] + graph[prevVertex][cur]:
                if (prevVertex, cur) not in removeList:
                    removeList.append((prevVertex, cur))
                    dq.append(prevVertex)


n, m = map(int, input().split())
edges = []
flag = [[True for _ in range(n + 1)] for _ in range(n + 1)]
graph = [dict() for _ in range(n + 1)]
reverseGraph = [[] for _ in range(n+1)]
for i in range(m):
    tmp = list(map(int, input().split()))
    edges.append(tmp)
    graph[tmp[0]][tmp[1]] = tmp[2]
    graph[tmp[1]][tmp[0]] = tmp[2]
    reverseGraph[tmp[0]].append([tmp[1], tmp[2]])
    reverseGraph[tmp[1]].append([tmp[0], tmp[2]])


removeList = []
dist = [float('inf') for _ in range(n + 1)]
min_ = dijkstra(1, n)
bfs()
tmp = -1
for from_, to_ in removeList:
    dist = [float('inf') for _ in range(n + 1)]
    flag[from_][to_] = False
    flag[to_][from_] = False
    tmp = max(tmp, dijkstra(1,n))
    flag[from_][to_] = True
    flag[to_][from_] = True

if tmp == float('inf'):
    print(-1)
else:
    print(tmp - min_)