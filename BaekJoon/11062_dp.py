import sys
input = sys.stdin.readline
sys.setrecursionlimit(30000)

#turn 0 : geun, 1 : myung
def game(s, e, turn):
    if dp[s][e]:
        return dp[s][e]

    if s >= e:
        if turn :
            dp[s][e] = ls[s]
            return dp[s][e]
        else:
            return 0

    if turn:
        dp[s][e] = max(game(s + 1, e, not turn) + ls[s], game(s, e - 1, not turn) + ls[e])
    else:
        dp[s][e] = min(game(s+1, e, not turn), game(s, e-1, not turn))
    return dp[s][e]


for _ in range(int(input())):
    n = int(input())
    ls = list(map(int,input().split()))
    dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
    print(game(0, n-1, 1))