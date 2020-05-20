#10799 쇠막대기
#20200327

stick = input()
stk = []
ans = 0

for i in range(len(stick)):
    num = len(stk)
    # ( 일때
    if stick[i] == '(':
        stk.append(stick[i])
    if stick[i] == ')':
        del stk[num-1]
        num -= 1
        if stick[i-1] == '(':
            ans += num
        else:
            ans += 1

print(ans)
