import sys
input = sys.stdin.readline

n = int(input())
ls = sorted(list(map(int,input().split())))
l = 0
r = n-1

ans = float('inf')
res = []
while l<r:

    tmp = ls[l] + ls[r]

    if abs(ans) > abs(tmp):
        ans = tmp
        res = [ls[l], ls[r]]

    if tmp > 0:
        r-=1
    elif tmp < 0:
        l+=1
    else:
        res = [ls[l], ls[r]]
        break

print(*res)