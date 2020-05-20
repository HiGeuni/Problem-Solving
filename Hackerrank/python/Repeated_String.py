s= input()
rep = int(input())

ans = s.count('a')* (rep//len(s)) + s[:(rep % len(s))].count('a')

print(ans)
