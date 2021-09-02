import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
ls = list(input().split())


buttonPM = 100000000

for i in range(1000001):
    flag = True
    tmp = list(str(i))
    for j in tmp:
        if j in ls:
            flag = False
            break
    if flag:
        buttonPM = min(buttonPM, len(str(i)) + abs(n-i))

print(min(buttonPM, abs(n-100)))
