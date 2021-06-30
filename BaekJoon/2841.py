import sys
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline

N,P = map(int,input().split())
ls = [[]for _ in range(7)]
cnt = 0
for _ in range(N):
    ta, tb = map(int,input().split())
    if len(ls[ta]) == 0:
        ls[ta].append(tb)
        cnt += 1
    else:
        if ls[ta][-1] < tb:
            ls[ta].append(tb)
            cnt += 1
        elif ls[ta][-1] == tb:
            continue
        else:
            while len(ls[ta]) != 0 and ls[ta][-1] > tb:
                ls[ta].pop()
                cnt += 1
            if len(ls[ta]) != 0 and ls[ta][-1] == tb:
                continue
            ls[ta].append(tb)
            cnt += 1
print(cnt)