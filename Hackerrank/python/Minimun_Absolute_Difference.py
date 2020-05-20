n = int(input())
arr = sorted(list(map(int, input().split())))

ans = 2000000000

for i in range(1, n):
    ans = min(abs(arr[i]-arr[i-1]), ans)

print(ans)
