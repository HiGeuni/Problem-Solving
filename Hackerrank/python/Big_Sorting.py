#str is faster than int!!

n = int(input())
ls = []
for _ in range(n):
    tmp = input()
    ls.append(tmp)
for a in sorted(sorted(ls), key = len):
    print(a)
