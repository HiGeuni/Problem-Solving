#봄버맨
import sys
input = sys.stdin.readline

#시간이 홀수일때 업데이트
def newBombs():
    tmpLs = []
    for i in range(row):
        for j in range(col):
            if grid[i][j] == 'O':
                tmpLs.append([i,j])
    return tmpLs

def evenTimeUpdate():
    global grid
    for i in range(row):
        for j in range(col):
            grid[i][j] = 'O'

def explode():
    global grid
    for bombX, bombY in bombs:
        grid[bombX][bombY] = '.'
        for i in range(5):
            if 0<=bombX+dx[i]<row and 0<=bombY+dy[i]<col:
                grid[bombX+dx[i]][bombY+dy[i]] = '.'


dx = [1,-1,0,0,0]
dy = [0,0,1,-1,0]

row,col,nSecond = map(int,input().split())

grid = [list(input().rstrip()) for _ in range(row) ]

bombs = []

#init
bombs = newBombs()
if nSecond != 1:    
    for curTime in range(2,nSecond+1):
        if curTime % 2 == 1:
            explode()
            bombs = newBombs()
        else:
            evenTimeUpdate()

for i in range(row):
    print(''.join(grid[i]))
