import sys
input = sys.stdin.readline

dx = [1,-1,0,0, 1, 1, -1, -1]
dy = [0,0,1,-1, 1, -1,1, -1]

n = int(input())
ls = [list(input().rstrip()) for _ in range(n)]
#x, y, cost
ans = [-1,-1, -1]

space = []
for i in range(n):
    for j in range(n):
        if ls[i][j] =='.':
            space.append([i,j])

for y, x in space:
    cnt = 0
    for d in range(8):
        ty = y
        tx = x
        ct = 0
        for i in range(n):
            ty += dy[d]
            tx += dx[d]
            if 0<=ty<n and 0<=tx<n:
                if ls[ty][tx] == 'B':
                    cnt += ct
                    break
                elif ls[ty][tx] == 'W':
                    ct +=1
                else:
                    break
            else:
                break
    if cnt != 0:
        if ans[2] < cnt:
            ans = [x,y,cnt]
        elif ans[2] == cnt:
            if ans[1] > y:
                ans = [x,y,cnt]
            elif ans[1] == y and ans[0] > x:
                ans = [x,y,cnt]
if ans == [-1,-1,-1]:
    print("PASS")
else:
    print(ans[0], ans[1])
    print(ans[2])
