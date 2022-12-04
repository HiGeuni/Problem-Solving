import sys
input = sys.stdin.readline

N = int(input())
ls = [ list(map(int, input().split())) for _ in range(N) ]
dp = [[[0,0,0] for _ in range(N)] for _ in range(N)]

# dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1]
# dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2]
# ls[i][j-1] == 0 and ls[i-1][j] == 0 -> dp[i][j][1] = d[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]

dp[0][1][0] = 1

for i in range(2, N):
    if ls[0][i] == 0:
        dp[0][i][0] = dp[0][i-1][0]
        
for i in range(1, N):
    for j in range(2, N):
        if ls[i][j] == 0 and ls[i-1][j] ==0 and ls[i][j-1] == 0:
            dp[i][j][2] = sum(dp[i-1][j-1])
        if ls[i][j] == 0:
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2]
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2]
            
print(sum(dp[N-1][N-1]))
