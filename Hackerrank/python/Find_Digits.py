
t = int(input())
for _ in range(t):
    n = int(input())
    rsv =n
    count = 0
    while n>0:
        mod = n % 10 
        if mod != 0 and rsv % mod == 0:
            count +=1
        n = int(n/10)
        
    print(count)
        
    
