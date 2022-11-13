import sys
input = sys.stdin.readline

def solution(rows, columns, queries):
    # init
    ls = [[0 for _ in range(columns)] for _ in range(rows)]
    c = 1
    for i in range(rows):
        for j in range(columns):
            ls[i][j] = c
            c += 1

    answer = []
    for x1, y1, x2, y2 in queries:
        # 가로 방향
        t = ls[x1-1][y1-1]
        tmp = ls[x1-1][y1-1]
        m = t
        for i in range(y1, y2):
            tmp = ls[x1-1][i]
            ls[x1-1][i] = t
            t = tmp
            m = min(m, t)
        for i in range(x1, x2):
            tmp = ls[i][y2-1]
            ls[i][y2-1] = t
            t = tmp
            m = min(m, t)
        for i in range(y2-2, y1-2, -1):
            tmp = ls[x2-1][i]
            ls[x2-1][i] = t
            t = tmp
            m = min(m, t)
        for i in range(x2-2, x1-2, -1):
            tmp = ls[i][y1-1]
            ls[i][y1-1] = t
            t = tmp
            m = min(m, t)
        answer.append(m)
    return answer
