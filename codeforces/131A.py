flag = True
s = list(input().rstrip())
for i in range(1, len(s)):
    if 'a'<=s[i]<='z':
        flag = False
        break
if flag:
    for i in range(len(s)):
        if 'a'<=s[i]<='z':
            s[i] = s[i].upper()
        else:
            s[i] = s[i].lower()
print(''.join(s))
