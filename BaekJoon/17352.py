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

def findParent(ta, tb):
    a = getParent(ta)
    b = getParent(tb)
    return a == b

n = int(input())

parent = [i for i in range(n+1)]

ans = 0
for i in range(n-2):
    s, d = map(int,input().split())
    unionParent(s, d)

for i in range(1,n+1):
    if findParent(1, i):
        continue
    else:
        print(getParent(1), getParent(i))
        unionParent(1, i)
