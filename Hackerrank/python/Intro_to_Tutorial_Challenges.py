V = int(input())
n = int(input())
ls = list(map(int, input().split()))

for i in range(n):
    if V == ls[i]:
        print(i)
        break
