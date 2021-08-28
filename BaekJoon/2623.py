import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int,input().split())

graph = [[] for _ in range(n+1)]
ind = [0 for _ in range(n+1)]
ans = []

for _ in range(m):
    ls = list(map(int,input().split()))
    if ls[0] == 0:
        continue
    prev = ls[1]
    for i in range(2, ls[0]+1):
        graph[prev].append(ls[i])
        prev = ls[i]
        ind[ls[i]] += 1

dq = deque()


for i in range(1, n+1):
    if ind[i] == 0:
        dq.append(i)

flag = True

while dq:
    cur = dq.pop()
    ans.append(cur)
    for j in graph[cur]:
        ind[j] -= 1
        if ind[j] == 0:
            dq.append(j)

for i in ind:
    if i == 1:
        flag = False
        break

if flag:
    for i in range(len(ans)):
        print(ans[i])
else:
    print(0)
