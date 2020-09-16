import sys
input = sys.stdin.readline

def change(d, c):
    if(c == "L"):
        d = (d-1)%4
    else:
        d = (d+1)%4
    return d

N = int(input())
board = [[0 for _ in range(N)]for _ in range(N)]
numApple = int(input())
for _ in range(numApple):
  x,y = map(int, input().split())
  board[x-1][y-1] = 1
numCommand = int(input())
command = [[0,0]]*10001
for i in range(numCommand):
  sec, direction = input().split()
  command[i] = [int(sec), direction]

curDirection = 0
dx = [0,1,0,-1]
dy = [1,0,-1,0]

curPosX = 0
curPosY = 0
answer = 0
idx = 0
visit = [[False for _ in range(N)]for _ in range(N)]
snake = []
snake.append((0,0))
visit[0][0] = True

while True:

  if answer == command[idx][0]:
    curDirection = change(curDirection,command[idx][1])
    idx += 1

  nx = curPosX + dx[curDirection]
  ny = curPosY + dy[curDirection]
  #보드판 안에 있는지
  if 0<=nx<N and 0<=ny<N and visit[nx][ny] == False:
    if board[nx][ny] == 1:
      board[nx][ny] = 0
      visit[nx][ny] = True
      snake.append((nx,ny))
    elif board[nx][ny] == 0:
      visit[nx][ny] = True
      snake.append((nx,ny))
      tx, ty = snake.pop(0)
      visit[tx][ty] = False
    curPosX = nx
    curPosY = ny
    answer += 1
  else:
    answer += 1
    break


print(answer)
