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
            tmpMax = max(tmpMax, max_[it][b])
            tmpMin = min(tmpMin, min_[it][b])
            b = parent[it][b]

    if a == b:
        print(tmpMin, tmpMax)
        return a

    for it in range(20, -1, -1):
        if parent[it][a] != parent[it][b]:
            tmpMax = max(tmpMax, max_[it][a], max_[it][b])
            tmpMin = min(tmpMin, min_[it][a], min_[it][b])
            a = parent[it][a]
            b = parent[it][b]

    tmpMax = max(tmpMax, max_[0][a], max_[0][b])
    tmpMin = min(tmpMin, min_[0][a], min_[0][b])
    print(tmpMin, tmpMax)
    return parent[0][b]


N = int(input())
depth = [0 for _ in range(N+1)]
parent = [[0 for _ in range(N+1)] for _ in range(21)]
min_ = [[0 for _ in range(N+1)] for _ in range(21)]
max_ = [[0 for _ in range(N+1)] for _ in range(21)]
graph = [dict() for _ in range(N+1)]
for i in range(N-1):
    ta, tb, tc = map(int,input().split())
    graph[ta][tb] = tc
    graph[tb][ta] = tc

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
            min_[0][i] = graph[cur][i]
            max_[0][i] = graph[cur][i]
            dq.append(i)

for i in range(1, 21):
    for j in range(1, N+1):
        parent[i][j] = parent[i-1][parent[i-1][j]]
        min_[i][j] = min(min_[i-1][j], min_[i-1][parent[i-1][j]])
        max_[i][j] = max(max_[i-1][j], max_[i-1][parent[i-1][j]])


for _ in range(int(input())):
    ta, tb = map(int,input().split())
    lca(ta, tb)