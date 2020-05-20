n,m = map(int, input().split())
ls = list(map(int, input().split()))
for _ in range(m):
    s,e = map(int, input().split())
    print(min(ls[s:e+1]))
