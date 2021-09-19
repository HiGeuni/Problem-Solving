n = int(input())
dp = [[0 for _ in range(10)] for _ in range(101)]
for i in range(10, 0, -1):
    dp[0][10-i] = i
dp[1][0] = sum(dp[0])

for i in range(1, 100):
    for j in range(1, 10):
        dp[i][j] = dp[i][j-1] - dp[i-1][j-1]
    dp[i+1][0] = sum(dp[i])

for _ in range(n):
    a = int(input())
    print(dp[a-1][0])