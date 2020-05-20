#2749 피보나치 수 3
#20200302

#initialize
dp = [0 for _ in range(1500010)]
dp[0], dp[1] = 0,1
for i in range(1500000):
    dp[i+2] = (dp[i+1] + dp[i]) % 1000000

print(dp[int(input())%1500000])
