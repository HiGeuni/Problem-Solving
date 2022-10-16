import sys
input = sys.stdin.readline

def decision(n):
    cnt = 0
    sum_ = 0
    for i in ls:
        if sum_ + i > n:
            sum_ = 0
            cnt += 1
        sum_ += i
    if sum_:
        cnt += 1
    return cnt > m

n,m = map(int,input().split())
ls = list(map(int,input().split()))

l = max(ls)
r = int(2e9)

while l <= r:
    mid = (l+r) // 2
    if decision(mid):
        l = mid + 1
    else:
        r = mid - 1

print(l)
