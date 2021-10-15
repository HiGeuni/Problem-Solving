s, n = map(int,input().split())
ls = []
for i in range(n):
    tmp = list(map(int,input().split()))
    ls.append(tmp)
ls = sorted(ls)
flag = True
for i in range(n):
    if s > ls[i][0]:
        s += ls[i][1]
    else:
        flag = Fgitalse
        break
print("YES" if flag else "NO")
