#Equal to 14003
import sys
from bisect import bisect_left
input = sys.stdin.readline

n = int(input())
ls = list(map(int,input().split()))

dp = [[0,0] for _ in range(n)]

dp[0] = [1,ls[0]]
tmp = [ls[0]]

i = 1
j = 2

while True:
    if i >= n:
        break
    if ls[i] > tmp[-1]:
        dp[i] = [j,ls[i]]
        tmp.append(ls[i])
        j+=1
    else:
        idx = bisect_left(tmp, ls[i])
        dp[i] = [idx+1, ls[i]]
        tmp[idx] = ls[i]
    i += 1
comp = len(tmp) 
ans = []
for i in range(len(dp)-1, -1 ,-1):
    if dp[i][0] == comp:
        ans.append(dp[i][1])
        comp -= 1

print(len(tmp))
for it in sorted(ans):
    print(it, end = ' ')
print()
