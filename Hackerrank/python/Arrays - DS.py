_ = input()
ls = list(map(int, input().split()))
ls.reverse()
for i in range(len(ls)):
    print(ls[i], end = ' ')
