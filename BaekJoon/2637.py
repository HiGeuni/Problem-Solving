import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
m = int(input())
degree = [0 for _ in range(n + 1)]
graph = [[] for _ in range(n + 1)]

for i in range(m):
    from_, to_, number = map(int,input().split())
    graph[to_].append([from_, number])
    degree[from_] += 1

visited = [0 for _ in range(n+1)]

dq = deque()
for i in range(1, n+1):
    if degree[i] == 0:
        dq.append(i)

cost = [[0 for _ in range(n+1)]for _ in range(n+1)]

while dq:
    cur = dq.popleft()
    for i, j in graph[cur]:
        flag = True
        for k in range(1, n+1):
            if cost[cur][k] != 0 :
                cost[i][k] += cost[cur][k] * j
                flag = False

        if flag:
            cost[i][cur] += j
        degree[i] -= 1
        if degree[i] == 0:
            dq.append(i)

for i in range(1, n+1):
    if cost[n][i] != 0:
        print(i, cost[n][i])