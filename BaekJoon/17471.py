import sys
from collections import deque
from itertools import combinations
input = sys.stdin.readline

def is_connected(tmpLs):
    start = tmpLs[0]
    dq = deque()
    dq.append(start)
    visited = set([start])
    tmpSum = 0
    cnt = 1
    while dq:
        v = dq.popleft()
        tmpSum += ls[v]
        for k in graph[v]:
            if k not in visited and k in tmpLs:
                cnt += 1
                dq.append(k)
                visited.add(k)
    flag = True if cnt == len(tmpLs) else False
    return tmpSum, flag


N = int(input())
ls = [0] + list(map(int,input().split()))
graph = [[]]
for i in range(1, N+1):
    tmp = list(map(int,input().split()))
    graph.append(tmp[1:])
res = 2e9
for i in range(1, N//2+1):
    for it in combinations(list(range(1, N+1)), i):
        groupA = list(it)
        groupB = []
        for j in range(1, N+1):
            if j not in it:
                groupB.append(j)
        sumA, boolA = is_connected(groupA)
        sumB, boolB = is_connected(groupB)
        if boolA and boolB:
            res = min(res, abs(sumA - sumB))

print(res if res != 2e9 else -1)