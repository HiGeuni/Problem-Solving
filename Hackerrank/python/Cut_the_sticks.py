# Enter your code here. Read input from STDIN. Print output to STDOUT

_ = int(input())
ar = list(map(int, input().split()))

while 1 :
    cnt = 0
    rmv = ar.count(0)
    for _ in range(rmv):
        ar.remove(0)
    if len(ar) == 0:
        break
    min_val = min(ar)
    for i in range(len(ar)):
        if ar[i] >= min_val:
            ar[i] -= min_val
            cnt+=1
    print(cnt)

#iterator cannot change value
