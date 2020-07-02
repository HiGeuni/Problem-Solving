n = int(input())
ans =0
#1
for i in range(1,n+1):
    element = list(map(int, str(i)))
    sum_ = sum(element) + i
    if sum_ == n:
        ans = i
        break
print(ans)
    
