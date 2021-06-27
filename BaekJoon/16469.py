#벽처리
import sys
from collections import deque
from heapq import heappush, heappop
input = sys.stdin.readline

dx, dy = [-1,0,1,0], [0,1,0,-1]

R, C = map(int,input().split())
graph = []
for _ in range(R):
    graph.append(input().rstrip())
villain = []
for i in range(3):
    x,y = map(int,input().split())
    villain.append([x-1, y-1, i])

visit = [[[2e9 for _ in range(C)]for _ in range(R)]for _ in range(3)]
for x, y, i in villain:
    dq = deque()
    dq.append([x,y])
    visit[i][x][y] = 0
    while dq:
        tx, ty = dq.popleft()
        for j in range(4):
            nx = tx + dx[j]
            ny = ty + dy[j]
            if 0<=nx<R and 0<=ny<C and visit[i][nx][ny] == 2e9 and graph[nx][ny] != '1':
                visit[i][nx][ny] = visit[i][tx][ty] + 1
                dq.append([nx,ny])

ans = [2e9,0]
for i in range(R):
    for j in range(C):
        tmp = max(visit[0][i][j], visit[1][i][j], visit[2][i][j])
        if tmp > ans[0]:
            continue
        elif tmp == ans[0]:
            ans[1] += 1
        else:
            ans[0] = tmp
            ans[1] = 1
if ans[0] == 2e9:
    print(-1)
else:
    print(ans[0])
    print(ans[1])
