import sys
from collections import deque
from heapq import heappush, heappop
input = sys.stdin.readline

dx1, dy1 = [-1,0,1,0], [0,1,0,-1]
dx2, dy2 = [-3, -3, -2, 2, 3, 3, 2, -2], [-2, 2, 3, 3, 2, -2, -3, -3]

visited = [[2e9 for _ in range(9)]for _ in range(10)]
elephant = list(map(int,input().split()))
king = list(map(int,input().split()))
dq = deque()
dq.append(elephant)
ans = 2e9
visited[elephant[0]][elephant[1]] = 0
while dq:
    curX, curY = dq.popleft()
    if [curX, curY] == king:
        ans = min(ans, visited[curX][curY])
        # break
    for i in range(4):
        nx = curX + dx1[i]
        ny = curY + dy1[i]
        if [nx,ny] == king:
            continue
        if 0<=nx<=10 and 0<=ny<=9:
            for j in range(2*i, 2*i + 2):
                nnx = curX + dx2[j]
                nny = curY + dy2[j]
                if j == 1 or j == 2:
                    tx = nnx + 1
                    ty = nny - 1
                elif j == 3 or j == 4:
                    tx = nnx - 1
                    ty = nny - 1
                elif j == 5 or j == 6:
                    tx = nnx - 1
                    ty = nny + 1
                else:
                    tx = nnx + 1
                    ty = nny + 1
                # print(nx, ny, tx, ty, j)
                if tx == king[0] and ty == king[1]:
                    continue
                if 0<=tx<10 and 0<=ty<9 and 0<=nnx<10 and 0<=nny<9 and visited[nnx][nny] == 2e9:
                    dq.append([nnx, nny])
                    visited[nnx][nny] = visited[curX][curY]+1

# for i in range(10):
#     for j in range(9):
#         print(visited[i][j], end = ' ')
#     print()
print(ans if ans != 2e9 else -1)