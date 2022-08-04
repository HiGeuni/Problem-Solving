import sys
import heapq as hq
input = sys.stdin.readline

def dijkstra(src):
    h = []
    hq.heappush(h, [0, src])
    visited = [2e9 for _ in range(N+1)]
    visited[src] = 0
    while h:
        cur = hq.heappop(h)
        # 연결된 노드
        for i in ls[cur[1]]:
            next_cost = i[1] + cur[0]
            if visited[i[0]] > next_cost:
                visited[i[0]] = next_cost
                updated[i[0]] = cur[1]
                hq.heappush(h, [next_cost, i[0]])

N, M = map(int,input().split())

ls = [[] for _ in range(N+1)]

updated = [0 for _ in range(N+1)]

for _ in range(M):
    s, d, w = map(int,input().split())
    ls[s].append([d, w])
    ls[d].append([s, w])

ans = N-1
dijkstra(1)
print(ans)
for i in range(2, N+1):
    print(i, updated[i])
