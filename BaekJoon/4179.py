# 4179
import sys
from collections import deque

input = sys.stdin.readline


def fireSpread():
    global fire
    global ls
    tmp = deque()
    while fire:
        x, y = fire.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < r and 0 <= ny < c:
                if visited[nx][ny] == 0 and ls[nx][ny] != '#':
                    ls[nx][ny] = 'F'
                    visited[nx][ny] = -1
                    tmp.append([nx, ny])
    fire = tmp
    return


def jihunMove():
    global jihun
    global ls
    global ans
    tmp = deque()
    while jihun:
        x, y = jihun.popleft()
        if (x == r - 1 or y == c - 1 or x == 0 or y == 0) and ls[x][y] != 'F':
            ans = ls[x][y] + 1
            return
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < r and 0 <= ny < c and ls[nx][ny] == '.' and ls[x][y] != 'F':
                ls[nx][ny] = ls[x][y] + 1
                tmp.append([nx, ny])
    jihun = tmp
    return


# J 초기 위치   F fire
r, c = map(int, input().split())
ls = [list(input().rstrip()) for _ in range(r)]
visited = [[0 for _ in range(c)] for _ in range(r)]

jihun = deque()
fire = deque()

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

ans = -1

# 초기 위치 받기
for i in range(r):
    for j in range(c):
        if ls[i][j] == 'J':
            jihun.append([i, j])
            ls[i][j] = 0

        if ls[i][j] == 'F':
            fire.append([i, j])
            visited[i][j] = -1

        if ls[i][j] == '#':
            visited[i][j] = -1

while jihun:
    jihunMove()
    fireSpread()
    if ans != -1:
        break

print(ans if ans != -1 else "IMPOSSIBLE")

