from collections import deque
import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def dfs(x, y):
    global visited
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if 0<=nx<n and 0<=ny<m and visited[nx][ny] == 0 and ls[nx][ny] == 1:
            visited[nx][ny] = 1
            dfs(nx, ny)

        
for _ in range(int(input())):
    m,n,k = map(int,input().split())
    ls = [[ 0 for _ in range(m)] for _ in range(n)]
    visited = [[0 for _ in range(m)] for _ in range(n)]
    
    for _ in range(k):
        row, col = map(int,input().split())
        ls[col][row] = 1
        
    cnt = 0
    
    for i in range(n):
        for j in range(m):
            if ls[i][j] == 1 and visited[i][j] == 0:
                visited[i][j] = 1
                dfs(i,j)
                cnt += 1
                
    print(cnt)
