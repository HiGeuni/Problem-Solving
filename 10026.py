#10026 적록색약
#20200301
#bfs

import sys
from collections import deque
sys.setrecursionlimit(100000)
dx = [0,0,1,-1]
dy = [1,-1,0,0]
n = int(input())
arr = [list(input()) for _ in range(n)]
visited = [[0 for _ in range(n)] for _ in range(n)]

def bfs(x,y):
    visited[x][y] = 1
    color = arr[x][y]
    dq = deque()
    dq.append((x,y))
    while dq:
        cx, cy = dq.popleft()
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if nx < n and ny < n and nx >=0 and ny>=0:
                if visited[nx][ny] == 0 and arr[nx][ny] == color:
                    dq.append((nx, ny))
                    visited[nx][ny] = 1

#normal
cnt = 0
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            bfs(i,j)
            cnt+=1
print(cnt, end = ' ')
        
for i in range(n):
    for j in range(n):
        if(arr[i][j] == 'G'):
            arr[i][j] = 'R'
visited = [[0 for _ in range(n)] for _ in range(n)]

cnt = 0
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            bfs(i,j)
            cnt+=1
print(cnt)
