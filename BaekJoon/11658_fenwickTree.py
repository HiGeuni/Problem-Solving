import sys
input = sys.stdin.readline

def update(r, c, value):
    tmp = c
    while r <= len(tree):
        c = tmp
        while c <= len(tree):
            tree[r][c] = tree[r][c] + value
            c += (c & -c)
        r += (r & -r)

def getSum(r, c):
    res = 0
    tmp = c
    while r != 0 and r < len(tree):
        c = tmp
        while c != 0 and c < len(tree):
            res += tree[r][c]
            c -= (c&-c)
        r -= (r & -r)
    return res


N,M = map(int,input().split())
ls = [[0] * (N+1)] + [[0] + list(map(int,input().split())) for _ in range(N)]
tree = [[0]* (N+1)  for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, N+1):
        update(i, j, ls[i][j])

for i in range(M):
    t = list(map(int,input().split()))
    if t[0] == 1:
        print(getSum(t[3], t[4]) - getSum(t[1]-1, t[4]) - getSum(t[3], t[2]-1) + getSum(t[1]-1, t[2]-1))
    else:
        update(t[1], t[2], t[3] - ls[t[1]][t[2]])
        ls[t[1]][t[2]] = t[3]