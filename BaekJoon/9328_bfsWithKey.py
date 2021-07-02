import sys
import math
from heapq import heappush, heappop
from collections import deque
input = sys.stdin.readline

dx = [1,-1,0,0]
dy = [0,0,1,-1]
for _ in range(int(input())):
    h,w = map(int,input().split())
    graph = []
    door = dict()
    hasKey = dict()
    graph.append(['.' for _ in range(w+2)])
    for i in range(h):
        tmp = ['.'] + list(input().rstrip())+ ['.']
        graph.append(tmp)
    graph.append(['.' for _ in range(w+2)])
    h += 2
    w += 2
    keyList = list(input().rstrip())
    for i in keyList:
        hasKey[i] = 1

    check = [[False for _ in range(w)]for  _ in range(h)]
    ans = 0
    dq = deque()
    dq.append([0,0])
    check[0][0] = True
    while dq:
        curX, curY = dq.popleft()
        for j in range(4):
            nx = curX + dx[j]
            ny = curY + dy[j]
            if 0<=nx<h and 0<=ny<w:
                if not check[nx][ny]:
                    if graph[nx][ny] == '$':
                        ans += 1
                        graph[nx][ny] = '.'
                        check[nx][ny] = True
                        dq.append([nx, ny])
                    elif graph[nx][ny].isupper():
                        if graph[nx][ny].lower() in hasKey:
                            graph[nx][ny] = '.'
                            check[nx][ny] = True
                            dq.append([nx,ny])
                    elif graph[nx][ny].islower():
                        hasKey[graph[nx][ny]] = 1
                        graph[nx][ny] = '.'
                        dq.append([nx, ny])
                        check = [[False for _ in range(w)] for _ in range(h)]
                        check[nx][ny] = True
                    elif graph[nx][ny] == '.':
                        check[nx][ny] = True
                        dq.append([nx,ny])
    # for i in range(h):
    #     print(check[i])
    print(ans)