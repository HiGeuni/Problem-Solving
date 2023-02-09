import sys
input = sys.stdin.readline

n, k = map(int,input().split())
ls = list(map(int,input().split()))

l = 0
r = sum(ls)

while l <= r:
    mid = (l + r) //2
    t = 0
    cnt = 0
    for i in range(n):
        t += ls[i]
        if t>=mid:
            cnt +=1 
            t = 0
    if cnt >= k:
        l = mid + 1
    else:
        r = mid -1

print(r)
