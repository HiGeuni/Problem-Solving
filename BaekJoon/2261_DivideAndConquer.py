import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**4)

def getDistance(ls1, ls2):
    return (ls1[0]-ls2[0]) **2 + (ls1[1] - ls2[1])**2

def closest(lst):
    if len(lst) <= 3:
        dst = 2e9
        for i in range(len(lst)):
            for j in range(i+1, len(lst)):
                dst = min(dst, getDistance(lst[i], lst[j]))
        return dst

    mid = len(lst)//2
    pointMid = lst[mid]

    lstL = lst[mid:]
    lstR = lst[:mid]

    distanseL = closest(lstL)
    distanseR = closest(lstR)

    d = min(distanseL, distanseR)

    points = []
    for i in range(len(lst)):
        if (lst[i][0] - pointMid[0])**2 < d:
            points.append(lst[i])

    if len(points) <= 1:
        return d

    points = sorted(points, key=lambda x:x[1])
    for i in range(len(points)):
        for j in range(i+1, len(points)):
            if (points[i][1] - points[j][1])**2 > d:
                break
            d = min(d, getDistance(points[i], points[j]))

    return d


n = int(input())
ls = [tuple(map(int,input().split())) for _ in range(n)]

if len(ls) != len(set(ls)):
    print(0)
else:
    ls = sorted(ls, key=lambda x:x[0])
    print(closest(ls))
