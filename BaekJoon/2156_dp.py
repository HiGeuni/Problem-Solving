import sys
input = sys.stdin.readline

ls = [0 for _ in range(10001)]
dp = [0 for _ in range(10001)]

n = int(input())
for i in range(1, n+1):
    ls[i] = int(input())
dp[1] = ls[1]
dp[2] = ls[1] + ls[2]
for i in range(3, n+1):
    dp[i] = max(max(dp[i-2] + ls[i], dp[i-3]+ls[i-1]+ls[i]), dp[i-1])

print(max(dp))
