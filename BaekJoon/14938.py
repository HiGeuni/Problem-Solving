import sys
import heapq as hq
input = sys.stdin.readline

def dijkstra(src):
    visited = [2e9 for _ in range(n+1)]
    h = []
    visited[src] = 0
    hq.heappush(h, [0,src])
    while h:
        cur = hq.heappop(h)
        # if visited[cur[1]] < cur[0]:
        #     continue
        for info in ls[cur[1]]:
            next_weight = cur[0] + info[0]
            if visited[info[1]] > next_weight:
                visited[info[1]] = next_weight
                hq.heappush(h, [next_weight, info[1]])

    return visited

n,m,r = map(int,input().split())

item = list(map(int,input().split()))

ls =[[] for _ in range(n+1)]

for _ in range(r):
    s,d,w = map(int,input().split())
    ls[s].append([w, d])
    ls[d].append([w, s])

ans = -1
for i in range(1,n + 1):
    visited = dijkstra(i)
    tmp = 0
    for j in range(1, n+1):
        if visited[j] <= m:
            tmp += item[j-1]
    ans = max(ans, tmp)

print(ans)
