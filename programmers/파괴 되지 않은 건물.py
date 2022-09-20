def solution(board, skill):
    answer = 0
    imos = [[0 for _ in range(len(board[0]) + 1)] for _ in range(len(board) + 1)]

    for line in skill:
        t, r1, c1, r2, c2, weight = line
        # attck
        if t == 1:
            weight *= -1

        # r1, c1 +
        imos[r1][c1] += weight
        # r1, c2 -
        imos[r1][c2+1] -= weight
        # r2, c1 - 
        imos[r2+1][c1] -= weight
        # r2, c2 + 
        imos[r2+1][c2+1] += weight
    
    for i in range(len(imos)):
        cur = 0
        for j in range(len(imos[0])):
            cur += imos[i][j]
            imos[i][j] = cur

    for i in range(len(imos[0])):
        cur = 0
        for j in range(len(imos)):
            cur += imos[j][i]
            imos[j][i] = cur

    for i in range(len(board)):
        for j in range(len(board[0])):
            board[i][j] += imos[i][j]
            if board[i][j] > 0:
                answer += 1
    return answer
