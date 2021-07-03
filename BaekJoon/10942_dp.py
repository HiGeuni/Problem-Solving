import sys
input = sys.stdin.readline

n = int(input())
ls = list(map(int,input().split()))
dp = [[False]*(n+1) for _ in range(n+1)]

for i in range(n):
    dp[i+1][i+1] = True
    if ls[i] == ls[i-1]:
        dp[i][i+1] = True
for i in range(2, n):
    for j in range(1, n-i+1):
        if ls[j-1] == ls[j+i-1] and dp[j+1][i+j-1]:
            dp[j][i+j] = True


for _ in range(int(input())):
    s,e = map(int,input().split())
    print(1 if dp[s][e] else 0)

