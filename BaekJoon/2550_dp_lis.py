import sys
from bisect import bisect_left
input = sys.stdin.readline
sys.setrecursionlimit(30000)

n = int(input())
left = list(map(int,input().split()))
right = list(map(int,input().split()))
dc = dict()
res = dict()
for i in range(n):
    dc[left[i]] = i+1
    res[i+1] = left[i]
for i in range(n):
    tmp = right[i]
    right[i] = dc[tmp]


tmp = []
lis = [right[0]]
tmp.append([0, right[0]])

for i in range(1, n):
    if right[i] > lis[-1]:
        lis.append(right[i])
        tmp.append([len(lis)-1, right[i]])
    else:
        idx = bisect_left(lis, right[i])
        lis[idx] = right[i]
        tmp.append([idx, right[i]])
# print(tmp)
ans = []
cnt = len(lis)-1
print(cnt+1)
for idx in range(len(tmp)-1, -1, -1):
    if tmp[idx][0] == cnt:
        cnt -= 1
        ans.append(res[tmp[idx][1]])

ans.sort()
for i in ans:
    print(i, end = ' ')
