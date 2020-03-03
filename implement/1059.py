#1059 수 2
#20200303

l = int(input())
ls = sorted(list(map(int, input().split())))
n = int(input())

s = 1

if n in ls:
    print(0)

else:
    for i in ls:
        if n > i:
            s = i+1
        else:
            e = i-1
            break
    print(e-s + (e-n)*(n-s))
