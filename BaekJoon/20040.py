import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def find(a):
    if parent[a] == a:
        return a
    parent[a] = find(parent[a])
    return parent[a]

def union(x, y):
    a = find(x)
    b = find(y)
    if parent[a] < parent[b]:
        parent[parent[a]] = parent[b]
    else:
        parent[parent[b]] = parent[a]
    return a == b

n, m = map(int,input().split())

parent = [i for i in range(n)]

ans = 0
for i in range(m):
    s, d = map(int,input().split())
    if union(s, d) and ans == 0:
        ans = i + 1

print(ans)
