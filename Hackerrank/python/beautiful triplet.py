#beautiful triplet
#20200221

n,m = map(int, input().split())
ls = list(map(int, input().split()))
cnt =0
for i in range(n-2):
    if ls[i] + m in ls and ls[i] + 2* m in ls:
        cnt +=1
        
print(cnt)
