import sys
import heapq as h
input = sys.stdin.readline

a,b = map(int,input().split())

ls = []

h.heappush(ls, [0, a])

ans = -2

while len(ls) != 0:
    tmp = h.heappop(ls)
    if (tmp[1]*2 == b) or (tmp[1]*10+1 == b):
        ans = tmp[0]+1
        break
    if (tmp[1]*2) < b:
       h.heappush(ls, [tmp[0]+1, tmp[1]*2])
    if (tmp[1]*10 + 1) < b:
        h.heappush(ls, [tmp[0]+1, tmp[1]*10+1])

print(ans+1)