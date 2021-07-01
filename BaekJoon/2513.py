import sys
from heapq import heappush, heappop
input = sys.stdin.readline

def negative():
    global ans
    tmpNeg = heappop(negDist)
    ans += 2 * abs(tmpNeg[0])
    if tmpNeg[1] > k:
        heappush(negDist, [tmpNeg[0], tmpNeg[1] - k])
        return
    tmpK = k - tmpNeg[1]
    while tmpK != 0:
        if len(negDist) == 0:
            break
        tmpStudent = heappop(negDist)
        if tmpK >= tmpStudent[1]:
            tmpK -= tmpStudent[1]
        else:
            heappush(negDist, [tmpStudent[0], tmpStudent[1] - tmpK])
            tmpK = 0

def positive():
    global ans
    tmpPos = heappop(posDist)
    ans += 2 * abs(tmpPos[0])
    if tmpPos[1] > k:
        heappush(posDist, [tmpPos[0], tmpPos[1] - k])
        return
    tmpK = k - tmpPos[1]
    while tmpK != 0:
        if len(posDist) == 0:
            break
        tmpStudent = heappop(posDist)
        if tmpK >= tmpStudent[1]:
            tmpK -= tmpStudent[1]
        else:
            heappush(posDist, [tmpStudent[0], tmpStudent[1] - tmpK])
            tmpK = 0


n,k,s = map(int,input().split())
negDist = []
posDist = []
for i in range(n):
    a,b = map(int,input().split())
    if s-a < 0:
        heappush(negDist, [s-a, b])
    else:
        heappush(posDist, [a-s, b])

ans = 0
while len(negDist) != 0 or len(posDist) != 0:
    if len(negDist) == 0:
        positive()

    elif len(posDist) == 0:
        negative()

    else:
        tPos = heappop(posDist)
        tNeg = heappop(negDist)

        heappush(posDist, tPos)
        heappush(negDist, tNeg)

        if abs(tPos[0]) > abs(tNeg[0]):
            positive()
        else:
            negative()

print(ans)

