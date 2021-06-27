import sys
from bisect import bisect_left
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(30000)

a = [False,False] + [True]*(1000001-1)
primes=[]
for i in range(2,1000001):
    if a[i]:
        primes.append(i)
        for j in range(2*i, 1000001+1, i):
            a[j] = False

def bfs():
    visit = [2e9 for _ in range(1000001)]
    dq = deque()
    dq.append(N)
    visit[N] = 0
    tm = 0
    while dq:
        tm += 1
        sz = len(dq)
        while sz:
            sz-=1
            cur = dq.popleft()
            for k in [cur + 1, cur // 2, cur //3, cur -1]:
                if k >= 1000001:
                    continue
                if k <= 0:
                    continue
                if visit[k] > tm:
                    visit[k] = tm
                    dq.append(k)
                    if A<=k<=B and k in primes:
                        return tm

for _ in range(int(input())):
    N,A,B = map(int,input().split())

    idx1 = bisect_left(primes, A)
    idx2 = bisect_left(primes, B)

    if idx1 == idx2 and primes[idx1] < A or primes[idx1] > B:
        print(-1)
    elif A<=N<=B and N in primes:
        print(0)
    else:
        print(bfs())