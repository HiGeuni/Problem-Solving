import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def getParent(ls, x):
    if ls[x] == x:
        return ls[x]
    ls[x] = getParent(ls, ls[x])
    return ls[x]

def unionParent(ls, a, b):
    global num
    a = getParent(ls, a)
    b = getParent(ls, b)
    if a != b:
        dc[b] = a
        num[a] += num[b]
        num[b] = num[a]

for _ in range(int(input())):
    m = int(input())
    dc = {}
    num = {}
    for _ in range(m):
        s1, s2 = input().split()
        if s1 not in dc:
            dc[s1] = s1
            num[s1] = 1
        if s2 not in dc:
            dc[s2] = s2
            num[s2] = 1
        unionParent(dc, s1, s2)
        print(num[getParent(dc, s1)])