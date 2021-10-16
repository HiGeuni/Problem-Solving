n,m = map(int,input().split())
num = 9
for _ in range(n-1):
    num *= 10
    num += 9

flag = False
ans = -1

for i in range(0, 10):
    tmp = num
    tmp -= i
    if tmp % m == 0 and tmp != 0:
        flag = True
        ans = tmp
        break
print(ans)
