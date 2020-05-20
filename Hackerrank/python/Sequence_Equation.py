n = int(input())
ls =[i for i in range(1,n+1)]

p = list(map(int, input().split()))

for j in range(len(ls)):
    for i in range(len(p)):
        if p[i] == ls[j]:
            rsv = i+1 
            break
    for i in range(len(p)):
        if p[i] == rsv:
            rsv = i+1
            break
    print(rsv)
    
    
