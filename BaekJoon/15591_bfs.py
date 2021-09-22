import sys
from collections import deque
input = sys.stdin.readline
n,q = map(int,input().split())
ls = [[] for _ in range(n+1)]

for _ in range(n-1):
    a,b,c = map(int,input().split())
    ls[a].append([b, c])
    ls[b].append([a, c])

for _ in range(q):
    a,b = map(int,input().split())
    cnt = 0
    q = deque()
    visited = [0 for _ in range(n+1)]
    visited[b] = 1

    for nxt, cost in ls[b]:
        visited[nxt] = 1
        q.append((nxt, cost))

    while q:
        cur, cost = q.popleft()
        # print(cur)
        if cost >= a:
            cnt += 1
            for nxt, nxtCost in ls[cur]:
                if visited[nxt] == 0:
                    visited[nxt] = 1
                    q.append((nxt, min(nxtCost, cost)))

    print(cnt)