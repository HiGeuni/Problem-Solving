n,d = map(int, input().split())
ls = list(map(int, input().split()))

for _ in range(d):
    a = ls.pop(0)
    ls.append(a)

for i in range(n):
    print(ls[i], end = ' ')
