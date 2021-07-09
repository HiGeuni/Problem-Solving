import sys
from collections import deque
input = sys.stdin.readline

dx = [1,1,1,0,0,-1,-1,-1]
dy = [1,0,-1,1,-1,1,0,-1]

def bfs(small, big):
    cnt = 0
    visited = [[False for _ in range(N + 1)] for _ in range(N + 1)]
    dq = deque()
    if small <= weights[postOffice[0]][postOffice[1]] <= big:
        dq.append(postOffice)
        visited[postOffice[0]][postOffice[1]] = True
    while dq:
        curX, curY = dq.popleft()
        for ni in range(8):
            nx = curX + dx[ni]
            ny = curY + dy[ni]
            if 0<=nx<N and 0<=ny<N and visited[nx][ny] == False:
                if small<= weights[nx][ny] <=big:
                    if graph[nx][ny] == 'K':
                        cnt += 1
                    if cnt == numHouse:
                        return True
                    visited[nx][ny] = True
                    dq.append([nx,ny])
    return False


N = int(input())
postOffice = []
houses = []
graph = []
numHouse = 0
for i in range(N):
    tmp = list(input().rstrip())
    graph.append(tmp)
    for j in range(N):
        if tmp[j] == 'P':
            postOffice = [i, j]
        if tmp[j] == 'K':
            numHouse+=1

minWeights = 2e9
maxWeights = -1
weights = []
ls = set()
for i in range(N):
    tmp = list(map(int,input().split()))
    for j in tmp:
        ls.add(j)
    weights.append(tmp)
    minWeights = min(minWeights, min(tmp))
    maxWeights = max(maxWeights, max(tmp))

ls = sorted(list(ls))
ans = float('inf')
l = 0
r = 0
while l < len(ls):
    flag = bfs(ls[l], ls[r])
    if flag:
     # print(l, r)
        ans = min(ans, ls[r]-ls[l])
        l += 1
    else:
        r += 1
    if r >= len(ls):
        break
print(ans)