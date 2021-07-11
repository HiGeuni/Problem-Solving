import sys
input = sys.stdin.readline

N, S = map(int,input().split())
ls = list(map(int,input().split()))
pSum = [0 for _ in range(N+1)]

pSum[0] = 0
for i in range(1, N+1):
    pSum[i] = pSum[i-1] + ls[i-1]

l = 0
r = 0
ans = 2e9
while l != N:
    tmp = pSum[r] - pSum[l]
    if tmp >= S:
        ans = min(ans, r-l)
        l += 1
    else:
        if r != N:
            r += 1
        else:
            l += 1
print(ans if ans != 2e9 else 0)