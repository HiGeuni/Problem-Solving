import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
cost = [0 for _ in range(N+1)]
graph = [[] for _ in range(N+1)]
deg = [0 for _ in range(N+1)]
for i in range(1, N+1):
    a = list(map(int,input().split()))
    cost[i] = a[0]
    for j in range(1, a[1]+1):
        graph[a[1+j]].append(i)
    deg[i] = a[1]

dq = deque()
dp = [0 for _ in range(N+1)]
for i in range(1, N+1):
    if deg[i] == 0:
        dq.append([i, cost[i]])
        dp[i] = cost[i]

total = 0
while dq:
    curNode, curCost = dq.popleft()
    total = max(curCost, total)
    for it in graph[curNode]:
        deg[it] -= 1
        dp[it] = max(dp[it], curCost + cost[it])
        if deg[it] == 0:
            dq.append([it, dp[it]])
            total = max(dp[it], total)

print(max(dp[1:]))
