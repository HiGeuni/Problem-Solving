t = 'hello'
idx = 0
s = input().rstrip()
for i in s:
    if i == t[idx]:
        idx += 1
        if idx == 5:
            break
print("YES" if idx == 5 else "NO")