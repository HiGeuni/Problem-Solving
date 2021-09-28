import sys
from itertools import product
input = sys.stdin.readline

n,m = map(int,input().split())
ls = sorted(list(map(int,input().split())))
for it in product(ls,repeat = m):
    for i in it:
        print(i, end = ' ')
    print()