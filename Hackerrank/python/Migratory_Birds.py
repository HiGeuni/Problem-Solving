n = int(input())
arr = list(map(int, input().split()))

max_val = -1
cnt = [0]
for i in range(1,6):
    cnt.append(arr.count(i))
    if(max_val < cnt[i]):
        max_val = cnt[i]
        ans = i
        
print(ans)
