# 10828 스택
#20200406

import sys
input = sys.stdin.readline

n = int(input())

ls = []

for i in range(n):
    command = input().rstrip().split()
    if command[0] == 'push':
        ls.append(int(command[1]))
    elif command[0] == 'top':
        if len(ls) == 0:
            print(-1)
        else:
            print(ls[len(ls)-1])
    elif command[0] == 'size':
        print(len(ls))
    elif command[0] == 'empty':
        if len(ls) == 0:
            print(1)
        else:
            print(0)
    elif command[0] == 'pop':
        if len(ls) == 0:
            print(-1)
        else:
            print(ls[len(ls)-1])
            del ls[len(ls)-1]

