import sys
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline

n = int(input())

bigBoy = []
smallBoy = []
bigGirl = []
smallGirl = []
tmpBoy = list(map(int,input().split()))
for it in tmpBoy:
    if it < 0:
        smallBoy.append(-it)
    else:
        bigBoy.append(it)

tmpGirl = list(map(int,input().split()))
for it in tmpGirl:
    if it < 0:
        smallGirl.append(-it)
    else:
        bigGirl.append(it)
bigBoy.sort()
smallBoy.sort()
bigGirl.sort()
smallGirl.sort()
cnt = 0

idx1 = 0
idx2 = 0
while True:
    if idx1 >= len(bigBoy) or idx2 >= len(smallGirl):
        break
    boy = bigBoy[idx1]
    girl = smallGirl[idx2]
    idx2+=1
    if girl > boy:
        cnt += 1
        idx1 += 1

idx1 = 0
idx2 = 0
while True:
    if idx1 >= len(smallBoy) or idx2 >= len(bigGirl):
        break
    boy = smallBoy[idx1]
    girl = bigGirl[idx2]
    idx1 += 1
    if boy > girl:
        cnt += 1
        idx2 += 1
print(cnt)