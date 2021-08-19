import sys
input = sys.stdin.readline

n = int(input())
ls = [list(map(int,input().split())) for _ in range(n)]

dp = [[0 for _ in range(n)] for _ in range(n)]

for i in range(1,n):
    for j in range(n-i):
        s = j
        e = i + j
        dp[s][e] = 2e9
        for k in range(s, e):
            dp[s][e] = min(dp[s][e], dp[s][k] + dp[k+1][e] + ls[s][0] * ls[k][1] * ls[e][1])

print(dp[0][n-1])