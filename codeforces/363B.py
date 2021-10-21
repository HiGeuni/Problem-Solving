import sys
input = sys.stdin.readline

n, k = map(int,input().split())
ls = list(map(int,input().split()))
min_ = sum(ls[:k])
tmp = min_
ans = 1
for i in range(1, n-k+1):
    tmp -= ls[i-1]
    tmp += ls[i+k-1]
    if tmp < min_:
        min_ = tmp
        ans = i+1
print(ans, min_)
