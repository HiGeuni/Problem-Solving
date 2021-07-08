import sys
from collections import deque
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    ls = list(map(int,input().split()))

    #indegree
    deg = [0 for _ in range(n+1)]
    graph = [[] for _ in range(n+1)]

    #make graph
    for i in range(0, n):
        for j in range(i+1, n):
            graph[ls[i]].append(ls[j])
            deg[ls[j]] += 1
    m = int(input())
    for i in range(m):
        cha, chb = map(int,input().split())
        if chb in graph[cha]:
            graph[cha].remove(chb)
            graph[chb].append(cha)
            deg[chb] -= 1
            deg[cha] += 1
        else:
            graph[chb].remove(cha)
            graph[cha].append(chb)
            deg[cha] -= 1
            deg[chb] += 1

    # print("graph : ", graph)
    # print("degree : ", deg)
    ans = []
    dq = deque()
    for i in range(1, n+1):
        if deg[i] == 0:
            dq.append(i)
            ans.append(i)

    if len(dq) == 0:
        flag = False
    else:
        flag = True

    while dq:
        if not flag or len(dq) != 1:
            flag = False
            break

        cur = dq.popleft()

        for it in graph[cur]:
            deg[it] -= 1
            if deg[it] == 0:
                dq.append(it)
                ans.append(it)
            elif deg[it] < 0:
                flag = False
                break

    if flag and len(ans) == n:
        print(*ans)
    else:
        print("IMPOSSIBLE")

