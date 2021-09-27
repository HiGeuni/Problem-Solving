import sys
from itertools import combinations_with_replacement
input = sys.stdin.readline

n,m = map(int,input().split())
ls = sorted(list(map(int,input().split())))
for it in combinations_with_replacement(ls,m):
    for i in it:
        print(i, end = ' ')
    print()