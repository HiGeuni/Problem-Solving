#9471 나이틍의 이동
#20200301
#bfs

#for using deque
from collections import deque

#iteratable dx, dy
idx = [2,2,1,1,-1,-1,-2,-2]
idy = [1,-1,2,-2,2,-2,1,-1]

#input test case
tc = int(input())

#define bfs
def bfs(start_x,start_y, dest_x, dest_y):
    visited[start_x][start_y] = 1
    dq = deque()
    dq.append((start_x, start_y))
    arr[start_x][start_y] = 1
    while dq:
        cur_x,cur_y = dq.popleft()
        if cur_x == dest_x and cur_y == dest_y:
            return arr[cur_x][cur_y] -1
        for i in range(8):
            next_x=cur_x+idx[i]
            next_y=cur_y+idy[i]
            if 0<=next_x<l and 0<=next_y<l and visited[next_x][next_y] == 0:
                dq.append((next_x, next_y))
                arr[next_x][next_y] = arr[cur_x][cur_y] +1
                visited[next_x][next_y] = 1

#input
while tc:
    l = int(input())
    arr = [[0] * l for _ in range(l)]
    visited = [[0]*l for _ in range(l)]
    sx, sy = map(int, input().split())
    dx, dy = map(int, input().split())
    if sx == dx and sy == dy:
        print(0)
        tc-=1
        continue
    ans = bfs(sx, sy, dx, dy)
    print(ans)
    tc-=1
