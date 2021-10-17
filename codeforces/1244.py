import sys
from math import ceil
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    ls = list(input().rstrip())
    ans = n
    max_ = 0
    for i in range(n):
        #left or right
        if ls[i] == '1':
            max_ = max(max_, i+1, n-i)
    print(2 * max_ if max_ else n)
