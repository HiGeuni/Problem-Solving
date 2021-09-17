import sys
input = sys.stdin.readline

def recursive(idx, val):
    global ans
    if idx == n:
        return
    ans.add(val + ls[idx])
    recursive(idx + 1, val + ls[idx])
    recursive(idx + 1, val)

n = int(input())
ls = list(map(int,input().split()))
ans = set(ls[:])
recursive(0,0)

for i in range(1, 2000000):
    if i not in ans:
        print(i)
        break
