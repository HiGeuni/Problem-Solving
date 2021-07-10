import sys
from collections import deque
input = sys.stdin.readline

def lca(a, b):
    #depth : a<b
    if depth[a] > depth[b]:
        tmp = a
        a = b
        b = tmp
    tmpMax = -1
    tmpMin = 2e9
    # depth 맞춰주
    for it in range(20, -1, -1):
        if depth[b] - depth[a] >= (1<<it):
            b = parent[it][b]

    if a == b:
        return a

    for it in range(20, -1, -1):
        if parent[it][a] != parent[it][b]:
            a = parent[it][a]
            b = parent[it][b]

    return parent[0][b]


N = int(input())
depth = [0 for _ in range(N+1)]
parent = [[0 for _ in range(N+1)] for _ in range(21)]
min_ = [[0 for _ in range(N+1)] for _ in range(21)]
max_ = [[0 for _ in range(N+1)] for _ in range(21)]
graph = [dict() for _ in range(N+1)]
for i in range(N-1):
    ta, tb= map(int,input().split())
    graph[ta][tb] = 1
    graph[tb][ta] = 1

dq = deque()
dq.append(1)
visited = [0 for _ in range(N+1)]
visited[1] = 1
while dq:
    cur = dq.popleft()
    for i in graph[cur]:
        if visited[i] == 0:
            visited[i] = 1
            depth[i] = depth[cur] + 1
            parent[0][i] = cur
            dq.append(i)

for i in range(1, 21):
    for j in range(1, N+1):
        parent[i][j] = parent[i-1][parent[i-1][j]]


for _ in range(int(input())):
    ta, tb = map(int,input().split())
    print(lca(ta, tb))