import sys
from heapq import heappush, heappop
input = sys.stdin.readline

def dijkstra():
    for it in range(k+1):
        visit[1][it] = 0
    h = []
    heappush(h, [0,1,0])
    while h:
        wei,cur,cnt = heappop(h)
        if wei > visit[cur][cnt]:
            continue
        for nextNode, cost in graph[cur]:
            nextCost = cost+wei
            #포장한 경우
            if cnt < k and wei < visit[nextNode][cnt+1]:
                visit[nextNode][cnt+1] = wei
                heappush(h, [wei,nextNode, cnt + 1])
            #포장 x
            if nextCost < visit[nextNode][cnt]:
                visit[nextNode][cnt] = nextCost
                heappush(h, [nextCost,nextNode, cnt])

n,m,k = map(int,input().split())
visit = [[float('inf') for _ in range(k+1)]for _ in range(n+1)]
graph = [[] for _ in range(n+1)]
for i in range(m):
    fr, to, weight = map(int,input().split())
    graph[fr].append([to, weight])
    graph[to].append([fr, weight])
dijkstra()
ans = float('inf')
for i in range(k+1):
    ans = min(ans, visit[n][i])
print(ans)
