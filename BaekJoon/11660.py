import sys
input = sys.stdin.readline

N, M = map(int, input().split())

ls = []
for _ in range(N):
  tmp = list(map(int, input().split()))
  ls.append(tmp)

cache = [[0 for _ in range(N+1)] for _ in range(N+1)]

for i in range(1,N+1):
  for j in range(1,N+1):
    cache[i][j] = ls[i-1][j-1] + cache[i][j-1] + cache[i-1][j] -cache[i-1][j-1]

for _ in range(M):
  x1, y1, x2, y2 = map(int, input().split())
  print(cache[x2][y2] - cache[x1-1][y2] - cache[x2][y1-1] + cache[x1-1][y1-1])
  