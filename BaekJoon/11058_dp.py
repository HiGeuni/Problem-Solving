import sys
input = sys.stdin.readline

n = int(input())
dp = [0]+ [i for i in range(1, n+1)]
for i in range(6, n+1):
    dp[i] = max(2*dp[i-3], 3*dp[i-4], 4*dp[i-5])
print(dp[-1])