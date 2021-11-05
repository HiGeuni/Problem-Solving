
n = int(input())
ls = list(map(int,input().split()))

if (ls[0] & 1) ^ (ls[1] & 1):
    if ls[0] & 1 == ls[2] & 1:
        print(2)
    else:
        print(1)
else:
    flag = ls[0] & 1
    for i in range(n):
        if ls[i] & 1 != flag:
            print(i+1)
            break
