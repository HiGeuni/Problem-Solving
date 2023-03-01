from collections import deque

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def rotate(arr, deg):
    if deg == 0:
        for i in range(len(arr)):
            tmp = arr[i][0]
            arr[i][0] = arr[i][1]*(-1)
            arr[i][1] = tmp
    elif deg == 1:
        for i in range(len(arr)):
            arr[i][0] *= (-1)
            arr[i][1] *= (-1)
    elif deg == 2:
        for i in range(len(arr)):
            tmp = arr[i][0]
            arr[i][0] = arr[i][1]
            arr[i][1] = tmp*(-1)
    arr = to_std(arr)
    return arr

def to_std(arr):
    arr = sorted(arr)
    std = [arr[0][0],arr[0][1]]
    for i in range(len(arr)):
        arr[i][0] -= std[0]
        arr[i][1] -= std[1]
    return arr

def find_blocks(arr, idx):
    length = len(arr)
    s = []
    visited = [[0 for _ in range(length)] for _ in range(length)]
    for i in range(length):
        for j in range(length):
            if arr[i][j] == idx and visited[i][j] == 0:
                a = [[i,j]]
                t = deque()
                t.append([i,j])
                visited[i][j] = 1
                while t:
                    cur = t.popleft()
                    cur_x = cur[0]
                    cur_y = cur[1]
                    for k in range(4):
                        nx = cur_x + dx[k]
                        ny = cur_y + dy[k]
                        if 0<=nx<length and 0<=ny<length and arr[nx][ny] == idx and visited[nx][ny] == 0:
                            a.append([nx, ny])
                            t.append([nx, ny])
                            visited[nx][ny] = 1
                s.append(to_std(a))
    return s

def solution(game_board, table):
    answer = 0
    board_blocks = find_blocks(game_board, 0)
    table_blocks = find_blocks(table, 1)
    #     블럭 찾기...
    dc = {}
    for i in board_blocks:
        for j in range(len(table_blocks)):
            if j in dc:
                continue
            flag = False
            if i == table_blocks[j]:
                answer += len(i)
                dc[j] = 1
                flag = True
            else:
                for k in range(3):
                    t = rotate(table_blocks[j], k)
                    if i == t:
                        answer += len(i)
                        dc[j] = 1
                        flag = True
                        break
                    table_blocks[j] = to_std(table_blocks[j])
            if flag:
                break
    return answer
