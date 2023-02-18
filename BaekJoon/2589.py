import sys
from collections import deque
input = sys.stdin.readline

dx = [ -1,1,0,0]
dy = [0,0,-1,1]

N, M = map(int, input().split())

map_ = [input().rstrip() for _ in range(N)]

def bfs(i, j):
    t = 0
    visited = [[0 for _ in range(M)] for _ in range(N)]
    dq = deque()
    dq.append([0, i, j])
    visited[i][j] = 1
    while len(dq):
        [cost, cx,cy] = dq.popleft()
        if t < cost:
            t = cost
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if 0<= nx < N and 0<=ny<M and map_[nx][ny] == 'L' and visited[nx][ny] == 0:
                nCost = cost + 1
                visited[nx][ny] = 1
                if nCost > t:
                    t = nCost
                dq.append([nCost, nx, ny])
    return t

ans = 0

for i in range(N):
    for j in range(M):
        if map_[i][j] == 'L':
            ans = max(ans, bfs(i, j))

print(ans)
