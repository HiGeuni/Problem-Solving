import sys
from collections import deque
from heapq import heappush, heappop
input = sys.stdin.readline
sys.setrecursionlimit(111111)
dx = dict()
dx['D'] = 1
dx['U'] = -1
dx['L'] = 0
dx['R'] = 0
dy = dict()
dy['D'] = 0
dy['U'] = 0
dy['L'] = -1
dy['R'] = 1
idx = 0

def dfs(x, y, c):
    # print(visited)
    global idx
    if visited[x][y] != 0:
        idx = visited[x][y]
        return
    visited[x][y] = c
    nx = x + dx[mat[x][y]]
    ny = y + dy[mat[x][y]]
    dfs(nx, ny, c)


N,M = map(int,input().split())
mat = [list(map(str, input().rstrip())) for _ in range(N)]
visited = [[0 for _ in range(M)]for _ in range(N)]
ans = 0
cnt = 0
dq = deque()
for i in range(N):
    for j in range(M):
        if visited[i][j] == 0:
            cnt += 1
            dfs(i, j, cnt)
            if idx == cnt:
                ans += 1
print(ans)