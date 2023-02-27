import sys
input = sys.stdin.readline

N,L,R,X = map(int,input().split())
ls = list(map(int,input().split()))

ans = 0

for i in range(3, (1<<N)+1):
    ts = 0
    tMax = -1
    tMin = 2e9
    for j in range(N):
        if i & 1<<j:
            ts += ls[j]
            tMax = max(tMax, ls[j])
            tMin = min(tMin, ls[j])
    if L<=ts<=R and tMax - tMin >= X:
        ans += 1
print(ans)
