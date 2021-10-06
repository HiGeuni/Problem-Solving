n = int(input())
ls = []
for _ in range(n):
    tmp = list(map(int,input().split()))
    ls.append(tmp)
ans = 2e20

for i in range(1, 2**n):
    sour = 1
    bit = 0
    for j in range(n):
        if i & (1<<j):
            sour *= ls[j][0]
            bit += ls[j][1]
    ans = min(ans, abs(sour-bit))
print(ans)
