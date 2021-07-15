import sys
input = sys.stdin.readline

N = int(input())
dp = [0 for _ in range(N+1)]
trace = [[] for _ in range(N+1)]
trace[1] = [1]

for i in range(2, N+1):
    dp[i] = dp[i-1] + 1
    trace[i] = trace[i-1] + [i]
    if i%3 == 0 and dp[i//3] + 1 < dp[i]:
        dp[i] = dp[i//3] + 1
        trace[i] = trace[i//3] + [i]
    if i%2 == 0 and dp[i//2] + 1 < dp[i]:
        dp[i] = dp[i//2] + 1
        trace[i] = trace[i//2] + [i]
print(dp[N])
ans = sorted(trace[N], reverse=True)
print(*ans)