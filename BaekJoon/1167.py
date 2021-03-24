import sys
from collections import deque
input = sys.stdin.readline

def bfs(start):
    cost = [0 for _ in range(n + 1)]
    dq = deque()
    dq.append([start,0])
    while dq:
        cur, cnt = dq.popleft()
        for dst, weight in graph[cur]:
            if cost[dst] == 0:
                cost[dst] = cnt + weight
                dq.append([dst, cost[dst]])
    return cost

n = int(input())
graph = [[] for _ in range(n+1)]

for i in range(1, n+1):
    tmp = list(map(int,input().split()))
    for it in range(1, len(tmp)-1, 2):
        graph[tmp[0]].append([tmp[it], tmp[it+1]])


tmp = bfs(1)
tmp[1] = 0
idx1 = tmp.index(max(tmp))
tmp = bfs(idx1)
tmp[idx1] = 0
idx2 = tmp.index(max(tmp))

print(max(tmp))