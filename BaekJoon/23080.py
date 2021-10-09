n = int(input())
s = input().rstrip()
ans = ''
cnt = n
for i in s:
    if cnt == n:
        ans += i
        cnt = 0
    cnt += 1
print(ans)
