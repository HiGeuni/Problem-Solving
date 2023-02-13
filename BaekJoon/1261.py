import sys
import heapq as hq
input = sys.stdin.readline

dx = [-1,1,0,0]
dy = [0,0,1,-1]

def dijkstra(src):
    visited = [[2e9 for _ in range(N)] for _ in range(M)]
    h = []
    visited[src[0]][src[1]] = 0
    hq.heappush(h, [0, src[0], src[1]])

    while h:
        # cur[0]: cost, cur[1]: x, cur[2]: y
        cur = hq.heappop(h)
        if visited[cur[1]][cur[2]] < cur[0]:
            continue
        for i in range(4):
            nx = cur[1] + dx[i]
            ny = cur[2] + dy[i]
            if 0<=nx<M and 0<=ny<N and visited[nx][ny] == 2e9:
                next_weight = cur[0]
                if ls[nx][ny] == '1':
                    next_weight += 1
                if visited[nx][ny] > next_weight:
                    visited[nx][ny] = next_weight
                    hq.heappush(h, [next_weight, nx, ny])
    return visited[M-1][N-1]


N, M = map(int,input().split())

ls = [input().rstrip() for _ in range(M)]

print(dijkstra([0,0]))
