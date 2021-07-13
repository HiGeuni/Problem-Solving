import sys
input = sys.stdin.readline

def find_parent(n):
    if parent[n] == n:
        return n
    parent[n] = find_parent(parent[n])
    return parent[n]

def union(n, m):
    a = find_parent(n)
    b = find_parent(m)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
N = int(input())
parent = [i for i in range(N+1)]
X = []
Y = []
Z = []
for i in range(1, N+1):
    x, y, z = map(int,input().split())
    X.append([x, i])
    Y.append([y, i])
    Z.append([z, i])
X.sort()
Y.sort()
Z.sort()
edges = []
for i in range(N-1):
    edges.append([X[i+1][0] -X[i][0], X[i][1], X[i+1][1]])
    edges.append([Y[i+1][0] - Y[i][0], Y[i][1], Y[i+1][1]])
    edges.append([Z[i+1][0] - Z[i][0], Z[i][1], Z[i+1][1]])
edges.sort()
ans = 0
for w, u, v in edges:
    if find_parent(u) != find_parent(v):
        union(u, v)
        ans += w
print(ans)
