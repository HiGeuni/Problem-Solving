s = list(map(str, input().split()))
size = [len(s[i]) for i in range(2)]
dif = size[1] - size[0]
res = 100000
for i in range(dif+1):
    cnt =0
    for j in range(size[0]):
        if s[0][j] != s[1][j+i]:
            cnt+=1
    res = min(res, cnt)

print(res)
    
        
