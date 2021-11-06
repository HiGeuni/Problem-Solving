import sys
input = sys.stdin.readline

limit = 1000001
primes = [False] * 2 + [True] * (limit - 2)
for i in range(2, limit):
  if primes[i]:
    for j in range(i ** 2, limit, i):
      primes[j] = False

n = int(input())
ls = list(map(int,input().split()))
for it in range(n):
    tmp = int(ls[it] ** 0.5)
    print("YES" if primes[tmp] and tmp ** 2 == ls[it] else "NO")
