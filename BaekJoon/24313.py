import sys
input = sys.stdin.readline

a1, a0 = map(int,input().split())
c = int(input())
n0 = int(input())
answer = -1

if c - a1 < 0:
    for i in range(n0, 101):
        answer = i < a0/(c-a1)
elif c - a1 == 0:
    answer = a0 <= 0
else:
    answer = n0 >= a0/(c-a1)

print(1 if answer else 0)
