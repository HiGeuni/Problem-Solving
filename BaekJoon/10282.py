import sys
import heapq as hq
input = sys.stdin.readline

def dijkstra(src):
    visited = [2e9 for _ in range(n+1)]
    h = []
    visited[src] = 0
    hq.heappush(h, [0, src])

    while h:
        cur = hq.heappop(h)
        if visited[cur[1]] < cur[0]:
            continue
        for info in ls[cur[1]]:
            next_weight = cur[0] + info[0]
            if visited[info[1]] > next_weight:
                visited[info[1]] = next_weight
                hq.heappush(h, [next_weight, info[1]])

    return visited

tc = int(input())
for _ in range(tc):
    n,d,c = map(int,input().split())
    ls = [[] for _ in range(n + 1)]
    for i in range(d):
        a, b, s = map(int,input().split())
        # ls[a].append([s, b])
        ls[b].append([s, a])
    cnt = 0
    max_ = 0
    for i in dijkstra(c):
        if i != 2e9:
            cnt += 1
            if i > max_:
                max_ = i
    print(cnt, max_)
