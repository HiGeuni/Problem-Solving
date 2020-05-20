n,k = map(int, input().strip().split())
c = list(map(int, input().strip().split()))

ans = 100 
i = k % n 
ans -= c[i] * 2 + 1 
while i != 0:
    i = (i + k) % n
    ans -= c[i] * 2 + 1
    
print(ans)
