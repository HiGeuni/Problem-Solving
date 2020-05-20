n = int(input())
ls = list(map(int, input().split()))
ls.sort()
ls.reverse()
ans =0
for i in range(n):
    ans += ls[i] * pow(2,i)

print(ans)
