import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
q = deque()
for _ in range(n):
    ls = input().rstrip().split()
    if ls[0] == "push":
        q.append(ls[1])
    elif ls[0] == "front":
        print(q[0] if len(q) != 0 else -1)
    elif ls[0] == "back":
        print(q[-1] if len(q) != 0 else -1)
    elif ls[0] == "size":
        print(len(q))
    elif ls[0] == "empty":
        print(1 if len(q) == 0 else 0)
    elif ls[0] == "pop":
        if len(q) == 0:
            print(-1)
        else:
            print(q.popleft())
