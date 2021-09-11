import sys
input = sys.stdin.readline

def solve(one, half):
    if one == 0:
        return 1
    if ls[one][half] != -1:
        return ls[one][half]
    ls[one][half] = 0
    ls[one][half] += solve(one-1,half+1)
    if half != 0:
        ls[one][half] += solve(one,half-1)
    return ls[one][half]


while True:
    ls = [[-1 for _ in range(31)] for _ in range(31)]
    n = int(input())
    if n == 0:
        break
    print(solve(n,0))
    
