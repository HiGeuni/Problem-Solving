import sys
import heapq as hq
input = sys.stdin.readline

MOD = 1000000007

tc = int(input())
for _ in range(tc):
    n = int(input())
    h = sorted(list(map(int,input().split())))
    answer = 1
    while len(h) > 1:
        a = hq.heappop(h)
        b = hq.heappop(h)
        t = a*b
        hq.heappush(h, t)
        answer = (answer * t) % MOD
        
    print(answer)
