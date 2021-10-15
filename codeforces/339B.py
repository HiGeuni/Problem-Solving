n, m = map(int,input().split())
ls = list(map(int,input().split()))
cur = 1
ans = 0
for i in range(m):
    if ls[i] == cur:
        continue
    elif ls[i] < cur:
        ans += n-cur+ls[i]
    else:
        ans += ls[i] - cur
    cur = ls[i]
print(ans)
