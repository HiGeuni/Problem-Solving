import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def find(a) :
    if parent[a] == a :
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


def get_distance(a, b):
    return round((pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2))**(1/2), 2)

n = int(input())

parent = [i for i in range(n)]

node = [list(map(float,input().split())) for _ in range(n)]

edges = []

for i in range(n):
    for j in range(n):
        if  i==j : continue
        edges.append([i, j, get_distance(node[i], node[j])])

edges.sort(key = lambda x : x[2])

cnt = 0
idx = 0
ans = 0.0

for cur in edges:
    flag = union(cur[0], cur[1])
    idx += 1
    if flag:
        continue
    else:
        cnt += 1
        ans += cur[2]

print(ans)
