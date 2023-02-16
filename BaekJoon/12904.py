import sys
input = sys.stdin.readline

s = input().rstrip()
t = input().rstrip()

ans = False

while True:
    if len(s) == len(t):
        if s == t:
            ans = True
        break
    if t[-1] == 'A':
        t = t[:-1]
    else:
        t = t[:-1]
        t = t[::-1]

print(1 if ans else 0)
