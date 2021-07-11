import sys
input = sys.stdin.readline

def squareIdx(tx, ty):
    return (tx//3)*3 + ty//3
flag = False

def go(x,y):
    global flag
    if flag:
        return True
    if x == 8 and y == 8:
        if board[x][y] == 0:
            for ti in range(1, 10):
                if not row[x][ti] and not col[y][ti] and not square[squareIdx(x, y)][ti]:
                    board[x][y] = ti
                    flag2 = True
                    break
            if flag2:
                for ti in range(9):
                    print(''.join(map(str, board[ti])))
                flag = True
                return True
            else:
                return False
        else:
            for ti in range(9):
                print(''.join(map(str, board[ti])))
            flag = True
            return True


    if board[x][y] != 0:
        return go(x, y+1) if y != 8 else go(x+1, 0)
    else:
        for ni in range(1, 10):
            if not row[x][ni] and not col[y][ni] and not square[squareIdx(x, y)][ni]:
                row[x][ni] = True
                col[y][ni] = True
                square[squareIdx(x,y)][ni] = True
                board[x][y] = ni
                go(x, y+1) if y != 8 else go(x+1, 0)
                board[x][y] = 0
                row[x][ni] = False
                col[y][ni] = False
                square[squareIdx(x,y)][ni] = False
    return False



board = [list(map(int, input().rstrip())) for _ in range(9)]
#init
row = [[False for _ in range(10)] for _ in range(9)]
col = [[False for _ in range(10)] for _ in range(9)]
square = [[False for _ in range(10)] for _ in range(9)]
for i in range(9):
    for j in range(9):
        if board[i][j] != 0:
            # i번 행에 board[i][j]가 있다.
            row[i][board[i][j]] = True
            # j번 열에 board[i][j]가 있다.
            col[j][board[i][j]] = True
            square[squareIdx(i, j)][board[i][j]] = True
go(0, 0)