n,m = map(int, input().split(' '))
ls = []
cnt =[]
ans = -1
res = 0
for _ in range(n):
    s = input()
    ls.append(s)
    
for i in range(n-1):
    for j in range(i+1, n):
        count = 0
        for k in range(0,m):
            if ls[i][k]=='1' or ls[j][k]=='1':
                count+=1
        if(ans < count):
            ans = count
            res = 1
        elif(ans == count):
            res +=1

print(ans)
print(res)
