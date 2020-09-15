import sys
import heapq
input = sys.stdin.readline

def dijkstra(N, start, distToHouse):
  dist = [2e9] * (N+1)
  dist[start] = 0
  q = []
  heapq.heappush(q, [0,start])

  while q:
    cost, position = heapq.heappop(q)

    for end, spendTime in distToHouse[position]:
      spendTime += cost
      if spendTime < dist[end]:
        dist[end] = spendTime
        heapq.heappush(q, [spendTime, end])
  return dist

N, M, X = map(int, input().split())

distToHouse = [[]for _ in range(N+1)]

for i in range(M):
  start, end, spendTime = map(int, input().split())
  distToHouse[start].append([end,spendTime])

answer = [0] * (N+1)
for i in range(1, N+1):
  ret = dijkstra(N, i, distToHouse)

  if i == X:
    for idx, r in enumerate(ret):
      answer[idx] += r
  else:
    answer[i] += ret[X]

print(max(answer[1:]))
