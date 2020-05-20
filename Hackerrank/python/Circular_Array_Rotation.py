#!/bin/python3

import collections

# Complete the circularArrayRotation function below.
def circularArrayRotation(a, k, queries):
    dq = collections.deque(a)
    for _ in range(k):
        a = dq.pop()
        dq.appendleft(a)
    for it in queries:
        print(dq[it])

nkq = input().split()
n = int(nkq[0])
k = int(nkq[1])
q = int(nkq[2])
a = list(map(int, input().rstrip().split()))
queries = []
for _ in range(q):
    queries_item = int(input())
    queries.append(queries_item)
circularArrayRotation(a, k, queries)
