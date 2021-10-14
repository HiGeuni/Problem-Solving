n = int(input())
ans = [0,0,0]
for _ in range(n):
    tmp = list(map(int,input().split()))
    for i in range(3):
        ans[i] += tmp[i]
print("YES" if ans == [0,0,0] else "NO")