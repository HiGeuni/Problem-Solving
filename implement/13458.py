#13458 시험 감독
#20200404

n = int(input())
ls = list(map(int, input().split()))
sup, sub = map(int, input().split())

ans = 0
for i in range(n):
    ls[i] -= sup
    ans += 1
    if ls[i] <= 0:
        continue
    if ls[i] % sub == 0:
        ans += (ls[i] // sub)
    else:
        ans += (ls[i]//sub+1)
        
print(ans)
