import sys
input = sys.stdin.readline

N, T =  map(int, input().split())
dp = [0 for _ in range(T+1)]
for i in range(N):
    time, score = map(int,input().split())
    for j in range(T, time - 1, -1):
        dp[j] = max(dp[j], dp[j-time] + score)

print(max(dp))
