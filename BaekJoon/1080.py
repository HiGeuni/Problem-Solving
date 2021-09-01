#1080
import sys
input = sys.stdin.readline

def change(x,y):
    for i in range(3):
        for j in range(3):
            ls1[x+i][y+j] = '1' if ls1[x+i][y+j] == '0' else '0'
    
def check():
    for i in range(n):
        for j in range(m):
            if ls1[i][j] != ls2[i][j]:
                return False
    return True

n,m = map(int,input().split())

ls1 = [list(input().rstrip()) for _ in range(n)]
ls2 = [list(input().rstrip()) for _ in range(n)]

cnt = 0

for i in range(n-2):
    for j in range(m-2):
        if ls1[i][j] != ls2[i][j]:
            change(i, j)
            cnt += 1
            
if check():
    print(cnt)
else:
    print(-1)
