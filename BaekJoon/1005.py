#1005
#By Topology sort

import sys
from collections import deque
input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    n, k = map(int,input().split())
    time = [0] + list(map(int,input().split()))
    degree = [0 for _ in range(n+1)]
    graph = [[] for _ in range(n+1)]

    for _ in range(k):
        from_, to_ = map(int,input().split())
        graph[from_].append(to_)
        degree[to_] += 1
    w = int(input())
    dq = deque()
    
    for i in range(1,n+1):
        if degree[i] == 0:
            dq.append(i)
    ans = [0 for _ in range(n+1)]
    
    while dq:
        cur = dq.popleft()
        for i in graph[cur]:
            ans[i] = max(ans[i], ans[cur] + time[cur])
            degree[i] -= 1
            if degree[i] == 0:
                dq.append(i)

    print(ans[w] + time[w])
    
