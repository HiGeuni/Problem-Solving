import sys
import heapq as hq
input = sys.stdin.readline

def dijkstra(src, dst):
    visited = [2e9 for _ in range(N+1)]
    h = []
    visited[src] = 0
    hq.heappush(h, [0, src])

    while h:
        cur = hq.heappop(h)
        if visited[cur[1]] < cur[0]:
            continue
        for info in ls[cur[1]]:
            next_weight = cur[0] + info[1]
            if visited[info[0]] > next_weight:
                visited[info[0]] = next_weight
                hq.heappush(h, [next_weight, info[0]])

    return visited[dst]


N, M = map(int,input().split())

ls = [[] for _ in range(N+1)]


for i in range(N-1):
    t = list(map(int,input().split()))
    ls[t[0]].append([t[1], t[2]])
    ls[t[1]].append([t[0], t[2]])

for _ in range(M):
    t = list(map(int,input().split()))
    print(dijkstra(t[0], t[1]))
