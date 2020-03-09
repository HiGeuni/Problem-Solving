#1890 점프
#20200309

#variables
n = int(input())
arr = [[0 for _ in range(n)] for _ in range(n)]
dp = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    arr[i] = list(map(int, input().split()))

#solve
dp[0][0] = 1

for i in range(n):
    for j in range(n):
        if i == n-1 and j == n-1:
            break
        if arr[i][j] + i < n:
            dp[i+arr[i][j]][j] += dp[i][j]
        if arr[i][j] + j < n:
            dp[i][j+arr[i][j]] += dp[i][j]
            
print(dp[n-1][n-1])
