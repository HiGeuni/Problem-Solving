#2740 행렬 곱셈
#20200404

n, m = map(int, input().split())
A = []
for i in range(n):
    row = list(map(int, input().split()))
    A.append(row)

m, k = map(int, input().split())
B = []
for i in range(m):
    row = list(map(int, input().split()))
    B.append(row)

ans = []

for i in range(k):
    ls_tmp = []
    for j in range(n):
        tmp = 0
        for h in range(m):
            tmp += A[j][h] * B[h][i]
        ls_tmp.append(tmp)
    ans.append(ls_tmp)

for i in range(n):
    for j in range(k):
        print(ans[j][i], end = ' ')
    print()
