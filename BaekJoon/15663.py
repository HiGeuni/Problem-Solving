import sys
from itertools import permutations
input = sys.stdin.readline

n,m = map(int,input().split())
ls = sorted(list(map(int,input().split())))

per = []
for it in permutations(ls, m):
    per.append(it)
per = sorted(list(set(per)))

for it in per:
    for i in it:
        print(i, end = ' ')
    print()
