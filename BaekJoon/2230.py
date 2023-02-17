import sys
input = sys.stdin.readline

N, M = map(int,input().split())

ls = sorted([int(input()) for _ in range(N)])

l = 0
r = 0
ans = 2e9 + 1

while l < N and r < N:
    tmp = ls[r] - ls[l]
    if tmp < M:
        r += 1
    else:
        l += 1
        ans = min(ans, tmp)

print(ans)
