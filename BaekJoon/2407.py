
cache = [[0 for _ in range(101)] for _ in range(101)] 

def combination(a,b):
  if b < 1 or a < 1 or a<b:
    return 0
  if cache[a][b] != 0:
    return cache[a][b]
  cache[a][b] = combination(a-1, b-1) + combination(a-1, b)
  return cache[a][b]

for i in range(1,101):
  cache[i][1] = i
  cache[i][i] = 1

n,m = map(int, input().split())
print(combination(n,m))
