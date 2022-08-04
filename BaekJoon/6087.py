import sys
from collections import deque
input = sys.stdin.readline

# 서 동 북 남
dx = [-1,1,0,0]
dy = [0,0,-1,1]

w, h = map(int, input().split())

ls = [input().rstrip() for _ in range(h)]

src = [0,0]

for i in range(h):
    for j in range(w):
        if ls[i][j] == 'C':
            src = [i,j]
            break

visited = [[-2 for _ in range(w)] for _ in range(h)]

dq = deque()
visited[src[0]][src[1]] = -1
dq.append(src)

while dq:
    cur = dq.popleft()
    if cur != src and ls[cur[0]][cur[1]] =='C':
        print(visited[cur[0]][cur[1]])
        break
    for i in range(4):
        nx = cur[0]
        ny = cur[1]
        while(True):
            nx += dx[i]
            ny += dy[i]
            if 0<=nx<h and 0<=ny<w:
                if ls[nx][ny] == "*":
                    break
                if (visited[nx][ny] == -2 or visited[nx][ny] > visited[cur[0]][cur[1]] + 1):
                    dq.append([nx,ny])
                    visited[nx][ny] = visited[cur[0]][cur[1]]+1
            else:
                break
