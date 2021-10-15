a, b = map(int,input().split())
new = a
old = 0
flag = True
ans = 0
while flag:
    if new != 0:
        ans += 1
        new -=1
        old += 1
    elif old >= b:
        old -= b
        old += 1
        ans += 1
    else:
        flag= False
print(ans)
