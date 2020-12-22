import sys
from queue import deque
input = sys.stdin.readline

n,m = map(int,input().split())

ls = [ list(map(int,input().split())) for _ in range(n)]
numMelt = [[0 for _ in range(m)] for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]

dx = [1,-1,0,0]
dy = [0,0,1,-1]

#bfs
def bfs(r,c):
    global visited
    dq = deque()
    dq.append([r,c])
    visited[r][c] = 1
    while dq:
        x,y = dq.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<n and 0<=ny<m and ls[nx][ny] != 0 and visited[nx][ny] == 0:
                visited[nx][ny] = 1
                dq.append([nx,ny])
#덩어리 수를 셉니다    
def num_dunguri():
    cnt = 0
    for i in range(n):
        for j in range(m):
            if ls[i][j] != 0 and visited[i][j] == 0:
                bfs(i,j)
                cnt+=1
    return cnt
            
#주변의 바다 수를 셉니다
def countMelt():
    global numMelt
    for i in range(n):
        for j in range(m):
            if ls[i][j] != 0:
                for k in range(4):
                    nx = i + dx[k]
                    ny = j + dy[k]
                    if 0<=nx<n and 0<=ny<m and ls[nx][ny] == 0:
                        numMelt[i][j] += 1
#녹입니다
def melt():
    global ls
    for i in range(n):
        for j in range(m):
            ls[i][j] -= numMelt[i][j]
            if ls[i][j] <0:
                ls[i][j] =  0
#numMelt와 visited초기화
def init():
    global numMelt
    global visited
    for i in range(n):
        for j in range(m):
            numMelt[i][j] = 0
            visited[i][j] = 0
    
ans = 0
while True:
    num = num_dunguri()
    #덩어리가 없으면
    if num == 0:
        ans = 0
        break
    #덩어리가 2개 이상이면
    elif num != 1:
        break
    init()
    countMelt()
    melt()
    ans+=1

print(ans)
