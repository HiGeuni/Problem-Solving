#2003 수들의 합 2
#20200310

n,m = map(int, input().split())
ls = list(map(int, input().split()))
psum = [ 0 for i in range(n+1)]

for i in range(n):
    psum[i+1] = ls[i] + psum[i]

ans = 0

for i in range(n):
    for j in range(i+1, n+1):
        if psum[j] < m:
            continue
        elif psum[j] - psum[i] >m:
            break
        elif psum[j] - psum[i] == m:
            ans +=1
            break
            
print(ans)

