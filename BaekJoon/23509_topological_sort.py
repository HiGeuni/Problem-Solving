import sys
import heapq as h
import copy
input = sys.stdin.readline

n = int(input())
nameToIdx = {}
names = [0 for _ in range(2*n)]
idx = 0
graph = [[] for _ in range(2*n)]
ind = [0 for _ in range(2*n)]

for _ in range(n):
    a,b = input().split()
    if a not in nameToIdx:
        nameToIdx[a] = idx
        names[idx] = a
        idx+=1
    if b not in nameToIdx:
        nameToIdx[b] = idx
        names[idx] = b
        idx += 1
    graph[nameToIdx[a]].append(nameToIdx[b])
    ind[nameToIdx[b]] += 1

ans = []
q = []
for i in range(idx):
    if ind[i] == 0:
        h.heappush(q, names[i])

tq = []
while q:
    cur = h.heappop(q)

    ans.append(cur)
    for nxt in graph[nameToIdx[cur]]:
        ind[nxt] -= 1
        if ind[nxt] == 0:
            h.heappush(tq, names[nxt])

    if len(q) == 0:
        q = copy.deepcopy(tq)
        tq = []

flag = True
for i in ind:
    if i != 0:
        flag = False

if flag:
    for i in ans:
        print(i)
else:
    print(-1)