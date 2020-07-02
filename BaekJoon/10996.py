n = int(input())
odd = n//2
if n%2 ==1:
    even = odd+1
else:
    even = odd

if n ==1 :
    print("*")
else:
    for i in range(2*n):
        if i % 2 == 0:
            for i in range(even):
                print("*", end = " ")
        else:
            for i in range(odd):
                print(" *", end = "")
        print()
    
            
            
