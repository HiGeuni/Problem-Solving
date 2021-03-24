import sys
input = sys.stdin.readline

n = int(input())
ls = sorted([int(input()) for _ in range(n)])
ans = 0
tmp = 1
for it in ls:
    if it >= tmp:
        ans += it - tmp
        tmp+=1
print(ans)