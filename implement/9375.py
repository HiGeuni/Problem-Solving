#9375 패션왕
#20200405

tc = int(input())

for i in range(tc):
    num = int(input())
    ls_type = []
    ls_num = []
    for j in range(num):
        n, m = input().split()
        if m in ls_type:
            ls_num[ls_type.index(m)] += 1
        else:
            ls_type.append(m)
            ls_num.append(1)
    ans = 1
    for it in ls_num:
        ans *= (it+1)
    print(ans-1)    
