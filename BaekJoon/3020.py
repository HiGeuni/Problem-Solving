import sys
from bisect import bisect_left
input = sys.stdin.readline

n,m = map(int,input().split())
cave = [int(input()) for _ in range(n)]
cave1 = []
cave2 = []
height = [0 for _ in range(m+1)]
for i in range(len(cave)):
    if i & 1 :
        cave1.append(cave[i])
    else:
        cave2.append(cave[i])
cave1.sort()
cave2.sort()

minNum = 2e9
minCnt = 0
for i in range(1,m+1):
    cnt1 = len(cave1) - bisect_left(cave1, m-i+1)
    cnt2 = len(cave2) - bisect_left(cave2, i)
    if cnt1 + cnt2 < minNum:
        minNum = cnt1 + cnt2
        minCnt = 1
    elif cnt1 + cnt2 == minNum:
        minCnt += 1
print(minNum, minCnt)