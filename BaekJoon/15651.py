def recursive(ans):
    
    if len(ans) == m:
        for i in range(m):
            print(ans[i], end = ' ')
        print()
        return
    
    newlst = ans[:]
 
    for i in range(1, n+1):
        newlst.append(i)
        recursive(newlst)
        newlst.pop()


n,m = map(int, input().split())
ls = []
for i in range(n):
    ls.append(i+1)
    recursive(ls)
    ls.pop()
    
