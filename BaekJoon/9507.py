def koong(n):
    if dp[n] != 0 :
        return dp[n]
    dp[n] = koong(n-1) + koong(n-2) + koong(n-3) + koong(n-4)
    return dp[n]
    
dp = [0 for _ in range(68)] 
dp[0] = 1, 
dp[1] = 1
dp[2] = 2
dp[3] = 4

for i in range(68):
    koong(i)
    
tc = int(input())
for _ in range(tc):
    n = int(input())
    print(dp[n])
