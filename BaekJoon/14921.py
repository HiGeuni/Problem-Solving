import sys
input = sys.stdin.readline

N = int(input())

ls = sorted(list(map(int,input().split())))

l = 0
r = len(ls)-1
ans = [2e9 + 1, 0, 0]

while l < r:
    tmp = ls[l] + ls[r]
    if abs(tmp) < abs(ans[0]):
        ans = [tmp, ls[l], ls[r]]
    if tmp < 0:
        l += 1
    else:
        r -= 1

print(ans[1]+ans[2])
