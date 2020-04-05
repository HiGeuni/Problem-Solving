#10866 덱
#20200405

import collections
import sys
input = sys.stdin.readline

dq = collections.deque()
n = int(input())
for i in range(n):
    a = input().rstrip()
    tmp = a.split(' ')
    if tmp[0] == 'front':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[0])
    elif tmp[0] == 'back':
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[len(dq)-1])
    elif tmp[0] == 'size':
        print(len(dq))
    elif tmp[0] == 'empty':
        if len(dq) == 0:
            print(1)
        else:
            print(0)
    elif tmp[0] == 'pop_front':
        if len(dq) == 0:
            print(-1)
        else:
            num = dq.popleft()
            print(num)
    elif tmp[0] == 'pop_back':
        if len(dq) == 0:
            print(-1)
        else:
            num = dq.pop()
            print(num)
    elif tmp[0] == 'push_front':
        dq.appendleft(int(tmp[1]))
    elif tmp[0] == 'push_back':
        dq.append(int(tmp[1]))
