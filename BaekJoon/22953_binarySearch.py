import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def bf(ls2, index, remainD):
    global ans
    if remainD == 0 or index >= len(ls2):
        l = 1
        r = 1_000_000_000_001
        while l<=r:
            tmp = 0
            mid = (l+r)//2
            for i in range(N):
                tmp += mid//ls2[i]
            if tmp >= K:
                r = mid - 1
                ans = min(ans, mid)
            else:
                l = mid + 1

        return
    if index >= len(ls2):
        return
    for i in range(remainD+1):
        if ls2[index] >= i+1:
            ls2[index] -= i
            bf(ls2, index+1, remainD-i)
            ls2[index] += i

N,K,C = map(int,input().split())
cook = list(map(int,input().split()))
ans = 2e13
bf(cook, 0, C)
print(ans)
