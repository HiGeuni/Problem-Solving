import sys
import math
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().split())
cost = [0] + list(map(int,input().split()))
graph = [[] for _ in range(n+1)]
for _ in range(m):
    u, v, w = map(int,input().split())
    graph[u].append([v, w])
    graph[v].append([u, w])
expense = []
dp = [[float('inf') for _ in range(2501)] for _ in range(n+1)]
heappush(expense, [0,cost[1], 1])
while expense:
    curCost, curMinStation, curLoc = heappop(expense)
    if curLoc == n:
        print(curCost)
        break
    if curCost > dp[curLoc][curMinStation]:
        continue
    for nextNode, weight in graph[curLoc]:
        nextCost = curCost + weight * curMinStation
        nextMin = min(curMinStation, cost[nextNode])
        if nextCost < dp[nextNode][nextMin]:
            dp[nextNode][nextMin] = nextCost
            heappush(expense, [nextCost, nextMin, nextNode])



