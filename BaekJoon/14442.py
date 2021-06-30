import sys
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline

dx = [1,-1,0,0]
dy = [0,0,1,-1]

n,m,k = map(int,input().split())
graph = [list(input().rstrip()) for _ in range(n)]
dist = [[[float('inf') for _ in range(m)] for _ in range(n)]for _ in range(k+1)]

dq = deque()
dq.append([0,0,0])
dist[0][0][0] = 1
while dq:
    curX,curY,cnt = dq.popleft()
    for i in range(4):
        nx = curX + dx[i]
        ny = curY + dy[i]
        if 0<=nx<n and 0<=ny<m:
            if graph[nx][ny] == '1':
                if cnt == k:
                    continue
                else:
                    if dist[cnt+1][nx][ny] > dist[cnt][curX][curY] + 1:
                        dist[cnt+1][nx][ny] = dist[cnt][curX][curY] + 1
                        dq.append([nx, ny, cnt+1])
            else:
                if dist[cnt][nx][ny] > dist[cnt][curX][curY]+1:
                    dist[cnt][nx][ny] = dist[cnt][curX][curY] + 1
                    dq.append([nx,ny,cnt])
ans = float('inf')
for i in range(k+1):
    ans = min(ans, dist[i][n-1][m-1])
print(ans if ans != float('inf') else -1)