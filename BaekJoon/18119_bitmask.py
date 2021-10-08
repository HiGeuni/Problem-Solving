import sys
input = sys.stdin.readline
v = ['a','e','i','o','u']
idxDc = {}
idx = 0
for i in range(26):
    if chr(97+i) not in v:
        idxDc[chr(97+i)] = idx
        idx += 1

ls = []
n, m = map(int, input().split())
for i in range(n):
    num = 0
    tmp = list(set(input().rstrip()))
    for j in tmp:
        if j not in v:
            num += 1<<idxDc[j]
    ls.append(num)

cur = (1<<22) -1
for i in range(m):
    cnt = 0
    cmd, alp = input().split()
    # 잊는다
    if cmd == '1':
        cur -= 1 << idxDc[alp]
    else:
        cur += 1 << idxDc[alp]

    for num in ls:
        if cur & num == num:
            cnt += 1
    print(cnt)
