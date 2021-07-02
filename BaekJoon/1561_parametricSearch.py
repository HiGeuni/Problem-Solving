import sys
import math
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().split())
ls = list(map(int,input().split()))
l = 0
r = 6e10
t = 0
while l <= r:
    mid = (l+r)//2
    cnt = m
    for i in range(m):
        cnt += mid//ls[i]
    if cnt >= n:
        t = mid
        r = mid - 1
    else:
        l = mid + 1

cnt = m
for i in range(m):
    cnt += (t-1)//ls[i]

for i in range(m):
    if t % ls[i] == 0:
        cnt += 1
    if cnt == n:
        print(i+1)
        break