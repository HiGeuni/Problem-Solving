import sys
from bisect import bisect_right
input = sys.stdin.readline

n = int(input())
x = sorted(list(map(int,input().split())))
for _ in range(int(input())):
    m = int(input())
    print(bisect_right(x, m))
