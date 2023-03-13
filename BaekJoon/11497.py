for _ in range(int(input())):
    n = int(input())
    ls = sorted(list(map(int,input().split())))
    res = 0
    for i in range(2,n):
        res = max(ls[i] - ls[i - 2], res)
    print(res)
