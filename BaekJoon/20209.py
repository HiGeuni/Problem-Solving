#20209
import sys
import copy
input = sys.stdin.readline

#스위치 누르는 모든 경우
def recursive(idx):
    if idx == k:
        pushSw(selectSw, cube) 
        return
    for i in range(5):
        selectSw[idx] = i
        recursive(idx + 1)

#ls : selectSw([0,0])
def pushSw(ls, cube2):
    global ans
    tmpCube = copy.deepcopy(cube2)
    # i번째 스위치(i+1만큼 값이 증가)
    for i in range(k):
         if ls[i] != 0:
            for j in sw[i]:
                 tmpCube[j-1] = (tmpCube[j-1] + (i+1) * ls[i]) % 5
    #모두 같은 값인지 check
    flag = True
    tmp = tmpCube[0]
    for i in range(1, len(tmpCube)):
        if tmp != tmpCube[i]:
            flag = False
    if flag == False:
        return
    sum_ = 0
    for i in ls:
        sum_ += i
    ans = min(ans, sum_)
    

n,k = map(int,input().split())

selectSw = [0 for _ in range(k)]

cube = list(map(int,input().split()))
sw = []
for _ in range(k):
    tmp = list(map(int,input().split()))
    sw.append(tmp[1:])

ans = 2e9

recursive(0)

print(ans if ans != 2e9 else -1)
