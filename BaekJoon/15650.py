def recursive(ans):
    
    if len(ans) == m:
        for i in range(m):
            print(ans[i], end = ' ')
        print()
        return
    
    back = ans[-1]
    newlst = ans[:]

    tmp = [0 for _ in range(n+1)]
    
    for i in range(len(newlst)):
        tmp[newlst[i]] = 1
        
    for i in range(1, n+1):
        if tmp[i] != 1 and i > back:
            newlst.append(i)
            recursive(newlst)
            newlst.pop()



n,m = map(int, input().split())
ls = []
for i in range(n):
    ls.append(i+1)
    recursive(ls)
    ls.pop()
    
