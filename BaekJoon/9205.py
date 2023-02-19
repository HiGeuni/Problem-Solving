import sys
from collections import deque
input = sys.stdin.readline

def dist(a,b,c,d):
    return abs(a-b) + abs(c-d) <= 1000

def bfs(x, y):
    dq = deque()
    dq.append([x, y])
    while dq:
        cx, cy = dq.popleft()
        # 갈 수 있으면
        if dist(cx, rock[0], cy, rock[1]):
            return True
        for i in range(t):
            if not visited[i]:
                nx, ny = conv[i]
                if dist(cx, nx, cy, ny):
                    dq.append([nx, ny])
                    visited[i] = True
    return False

for _ in range(int(input())):
    t = int(input())
    home = list(map(int,input().split()))
    conv = [list(map(int, input().split())) for _ in range(t)]
    visited = [False for _ in range(t)]
    rock = list(map(int,input().split()))

    print("happy" if bfs(home[0], home[1]) else "sad")
