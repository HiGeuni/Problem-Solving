#2240 자두나무
#20200408

t, w = map(int, input().split())
dp = [[0 for i in range(t)] for _ in range(w+1)]
ls = [0] * t

#initialization & input
for i in range(t):
    ls[i] = int(input())
    if i == 0:
        if ls[i] == 1:
            dp[0][i] = 1
            dp[1][i] = 0
        else:
            dp[1][i] = 1
            dp[0][i] = 0
    else:
        if ls[i] == 1:
            dp[0][i] = dp[0][i-1] + 1
        else:
            dp[0][i] = dp[0][i-1]
            
#solve
for i in range(1, t):
    val = ls[i]
    for j in range(1, w+1):
        if j % 2 == 0: # 1번 나무에 서 있다.
            if val == 1: # 자두나무가 1번에 있을 떄 ++
                dp[j][i] = max(dp[j][i-1]+1, dp[j-1][i-1])
                #print(1, i, j, dp)
                
            else:
                dp[j][i] = max(dp[j][i-1], dp[j-1][i-1]+1)
                #print(2, i, j, dp)
        else: # 2번 나무에 서 있다.
            if val == 1: # 자두나무가 2번에 있을 때 --
                dp[j][i] = max(dp[j][i-1], dp[j-1][i-1]+1)
                #print(3, i, j, dp)
            else:
                dp[j][i] = max(dp[j][i-1]+1, dp[j-1][i-1])
                #print(4, i, j, dp)
                
ans = -1
for i in range(w+1):
    ans = max(ans, dp[i][t-1])
    
print(ans)
