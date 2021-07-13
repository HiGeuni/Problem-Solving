import sys
from bisect import bisect_left
input = sys.stdin.readline

N = int(input())
ls = list(map(int,input().split()))
tmp = [ls[0]]
for i in range(1, len(ls)):
    if tmp[-1] < ls[i]:
        tmp.append(ls[i])
    else:
        idx = bisect_left(tmp, ls[i])
        tmp[idx] = ls[i]
print(len(tmp))
