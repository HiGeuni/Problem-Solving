n = int(input())
ls = [list(map(int,input().split())) for _ in range(n)]
ls = sorted(ls, key = lambda x:(x[0], x[1]))
for it in ls:
    print(*it)
