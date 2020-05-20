#Minimum Distances
#20200223

n, ls=input(),list(map(int,input().split()))
ans = 10000
for x in ls:
    dif=(len(ls) -1 - ls[::-1].index(x))-ls.index(x)
    if dif != 0 and dif<ans:
        ans = dif
if ans == 10000:
    print(-1)
else:
    print(ans)
