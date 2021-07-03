import sys
input = sys.stdin.readline

n = int(input())
ls = list(map(int, input().split()))
dp = [[0 for _ in range(21)] for _ in range(n)]

dp[0][ls[0]] = 1

for i in range(1, n):
    for j in range(21):
        if dp[i-1][j] != 0:
            tmp = dp[i-1][j]
            if 0<= j+ls[i] <21:
                dp[i][j+ls[i]] += tmp
            if 0<= j-ls[i] < 21:
                dp[i][j-ls[i]] += tmp
print(dp[n-1])