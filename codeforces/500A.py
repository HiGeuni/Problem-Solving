n, t = map(int,input().split())
ls = [0] + list(map(int,input().split()))
cur = 1
flag = False
while cur < n:
    if cur == t:
        flag = True
        break
    cur += ls[cur]
if cur == n and n == t:
    flag = True
print("YES" if flag else "NO")
