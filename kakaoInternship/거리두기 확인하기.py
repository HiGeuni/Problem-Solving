visited = [[False for _ in range(5)] for _ in range(5)]
flag = True
dx = [1,-1,0,0]
dy = [0,0,1,-1]

def dfs(x, y, d, places):
    global visited
    global flag
    if d == 2:
        return
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<5 and 0<=ny<5 and not visited[nx][ny]:
            if places[nx][ny] == 'P':
                flag = False
                break
            elif places[nx][ny] == 'X':
                continue
            else:
                visited[nx][ny] = True
                dfs(nx, ny, d+1, places)
                visited[nx][ny] = False
    return


def solution(places):
    global flag
    global visited
    answer = []
    for tc in range(5):
        for i in range(5):
            for j in range(5):
                visited[i][j] = False
        flag = True
        for i in range(5):
            for j in range(5):
                if not visited[i][j] and places[tc][i][j] == 'P':
                    visited[i][j] = True
                    dfs(i, j, 0, places[tc])
                    visited[i][j] = False
        if flag :
            answer.append(1)
        else:
            answer.append(0)

    return answer
