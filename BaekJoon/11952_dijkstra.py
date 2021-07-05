import sys
from collections import deque
from heapq import heappush, heappop
input = sys.stdin.readline

def dijkstra():
    dist = [float('inf') for _ in range(N+1)]
    h = []
    dist[1] = 0
    heappush(h, [0, 1])
    while h:
        curCost, curLoc = heappop(h)
        if dist[curLoc] < curCost:
            continue
        for nextLoc in graph[curLoc]:
            if occupied[nextLoc]:
                continue
            cost = curCost
            if infectedFlag[nextLoc]:
                cost += q
            else:
                cost += p
            if cost < dist[nextLoc]:
                dist[nextLoc] = cost
                heappush(h,[cost, nextLoc])
    return dist[N] - q if infectedFlag[N] else dist[N] - p
    # return dist

def bfs():
    dq = deque()
    for it in occupy:
        dq.append([it, 0])
    while dq:
        curLoc, cnt = dq.popleft()
        if infectedFlag[curLoc]:
            continue
        infectedFlag[curLoc] = True
        if cnt == S:
            continue
        for s in graph[curLoc]:
            dq.append([s, cnt+1])


N, M, K, S = map(int,input().split())
p,q = map(int,input().split())

occupy = list(int(input()) for _ in range(K))

graph = [dict() for _ in range(N+1)]
for i in range(M):
    from_, to_ =map(int,input().split())
    graph[from_][to_] = 1
    graph[to_][from_] = 1

occupied = [i in occupy for i in range(N+1)]
infectedFlag = [False for _ in range(N+1)]
bfs()
# print(infectedFlag)
print(dijkstra())