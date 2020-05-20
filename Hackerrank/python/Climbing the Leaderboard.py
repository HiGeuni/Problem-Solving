#How to Use bisect ( bisect_left = lower_bound, bisect_right = upper_bound)

import bisect

n = int(input())
scores = sorted(set(map(int, input().split())))

m = int(input())
alice = map(int, input().split())

for i in alice:
    print(len(scores) - bisect.bisect_right(scores,i)+1)
