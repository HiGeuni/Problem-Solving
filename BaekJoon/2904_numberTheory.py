import sys
import math
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline

def eratos(num):
    prime_ = [True] * num
    tmp = int(math.sqrt(num))+1
    for k in range(2, tmp+1):
        if prime_[k]:
            for l in range(2*k, num, k):
                prime_[l] = False
    return [k for k in range(2, num) if prime_[k] == True]

prime = eratos(1000001)
primeCnt = dict()
n = int(input())
ls = list(map(int,input().split()))
numCnt = [dict() for _ in range(n)]
for it in range(n):
    tmpIt = ls[it]
    for pNum in prime:
        while tmpIt % pNum == 0:
            tmpIt /= pNum
            if pNum in numCnt[it]:
                numCnt[it][pNum] += 1
            else:
                numCnt[it][pNum] = 1
            if pNum in primeCnt:
                primeCnt[pNum] += 1
            else:
                primeCnt[pNum] = 1

res = 1
for i in primeCnt:
    primeCnt[i] //= n
    if primeCnt[i] != 0:
        res *= (i**primeCnt[i])

print(res, end = ' ')

ans = 0
for i in range(n):
    for j in primeCnt:
        if j in numCnt[i]:
            if numCnt[i][j] < primeCnt[j]:
                ans += primeCnt[j] - numCnt[i][j]
        else:
            ans += primeCnt[j]
print(ans)