n = int(input())
ls = list(map(int, input().split()))

cnt = -1
i=0

while i<n:
    if i+2 < n and ls[i+2] == 0:
        i+=2
    else:
        i+=1
    cnt+=1

print(cnt)
