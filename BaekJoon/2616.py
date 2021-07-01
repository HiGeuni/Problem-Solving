import sys
input = sys.stdin.readline

res = 0
n = int(input())
preSum = [0 for _ in range(n+1)]
ls = list(map(int,input().split()))
for i in range(1,len(ls)+1):
    preSum[i] = preSum[i-1] + ls[i-1]
cnt = int(input())

ans = 0
dp = [[0 for _ in range(n+1)] for _ in range(4)]

for j in range(1, 4):
    for i in range(j*cnt, n+1):
        dp[j][i] = max(dp[j][i-1], dp[j-1][i-cnt] + preSum[i] - preSum[i-cnt])
print(dp[3][n])