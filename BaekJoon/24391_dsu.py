import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def getParent(n):
    if parent[n] == n:
        return n
    else:
        parent[n] = getParent(parent[n])
        return parent[n]

def unionParent(ta,tb):
    ta = getParent(ta)
    tb = getParent(tb)
    if ta != tb:
        parent[tb] = ta


n, m = map(int,input().split())

parent = [i for i in range(n+1)]

ans = 0
for i in range(m):
    s, d = map(int,input().split())
    unionParent(s, d)

ls = list(map(int,input().split()))

for i in range(n-1):
    if getParent(ls[i]) != getParent(ls[i+1]):
        ans += 1
print(ans)
