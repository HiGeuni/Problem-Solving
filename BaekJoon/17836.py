import sys
from collections import deque
input = sys.stdin.readline

dx = [-1,1,0,0]
dy = [0,0,1,-1]

def bfs():
    ans = 2e9
    #x, y, time
    dq = deque()
    dq.append([0,0])
    visit = [[0 for _ in range(M)] for _ in range(N)]
    # visit[0][0] = 1
    while dq:
        x, y= dq.popleft()

        if ls[x][y] == 2:
            ans = min(ans, visit[x][y] + swordToPeach)
        if x == N-1 and y == M-1:
            return min(ans, visit[x][y])
        for di in range(4):
            nx = x + dx[di]
            ny = y + dy[di]
            if 0<=nx<N and 0<=ny<M and not visit[nx][ny] and ls[nx][ny] != 1:
                visit[nx][ny] = visit[x][y] + 1
                dq.append([nx,ny])
    return ans


N, M, T= map(int,input().split())
sword = []
swordToPeach = 0
ls = []
for i in range(N):
    ls.append(list(map(int,input().split())))
    for j in range(M):
        if ls[i][j] == 2:
            sword = [i, j]

swordToPeach = N-sword[0] + M-sword[1] -2

res = bfs()
if res > T:
    res = "Fail"
print(res)