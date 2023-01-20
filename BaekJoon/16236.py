# 16236 아기 상어
# N x N 물고기 M마리, 아기 상어 1마리
# 아기 상어 크기 : 2, 1초에 상하좌우로 인접한 한 칸씩 이동
# 자기보다 큰 물고기가 있는 칸은 지나갈 수 없음.
# 자신의 크기보다 작은 물고기만 먹을 수 있음.
# 자신의 크기와 같은 수의 물고기를 먹을 때마다 크기가 1 증가
# 1. 더이상 먹을 수 있는 물고기가 없다면 엄마한테 도움 요청
# 2. 먹을 수 있는 물고기가 1마리면, 그 물고기를 먹는다.
# 3. 먹을 수 있는 물고기가 1마리보다 많으면, 거리가 가장 가까운 물고기를 먹으러 간다.
#   거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값
#   거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기
# 이동은 1초가 걸리고, 물고기를 먹는데 걸리는 시간은 없다.
# 0은 공백, 1,2,3,4,5,6은 칸에 있는 물고기의 크기

# 거리를 계산할 때 bfs

import sys
from collections import deque
input = sys.stdin.readline

dx = [0,0,1,-1]
dy = [1,-1,0,0]

# def compare(x, y):
#   if x[0] > y[0]:
#     return 1
#   else:
#     if x[1] > y[1]:
#       return 1
#     if x[2] > y[2]:
#       return 1

# bfs
# retrun [거리, 상어위치]
def getCandidate(start, n):
    visited = [[False for _ in range(n)] for _ in range(n)]
    dq = deque()
    dq.append([start[0], start[1], 0])
    m[start[0]][start[1]] = 0
    res = []
    while dq:
        cur = dq.popleft()
        for i in range(4):
            nx = cur[0] + dx[i]
            ny = cur[1] + dy[i]
            if 0<= nx <n and 0<=ny<n and not visited[nx][ny]:
                visited[nx][ny] = True
                # 갈 수 있는 경우
                if m[nx][ny] == 0 or m[nx][ny] == start[2]:
                    dq.append([nx, ny, cur[2] + 1])          
                elif m[nx][ny] < start[2]:
                    res.append([cur[2] + 1, nx, ny])
    return sorted(res)

n = int(input())
m = [list(map(int, input().split())) for _ in range(n)]

# x, y, 크기
shark = []

# 상어 위치
for i in range(n):
    for j in range(n):
        if m[i][j] == 9:
            shark = [i, j, 2]
            break
        if shark != []:
            break

flag = True
ans = 0
eat_cnt = 0

while flag:
    m[shark[0]][shark[1]] = 0
    cand = getCandidate(shark, n)
    # if 없으면
    if len(cand) == 0:
        break
    # else Eat cand[0]!
    # eat_cnt += 1
    # 먹는 로직 설계
    # 1. 1개밖에 없을 때
    # 2. 가장 가까운게 많다면?
    else:
        m[cand[0][1]][cand[0][2]] = 0
        # 위치
        shark[0] = cand[0][1]
        shark[1] = cand[0][2]
        ans += cand[0][0]
        eat_cnt += 1
    if eat_cnt == shark[2]:
        shark[2] += 1
        eat_cnt = 0

print(ans)
