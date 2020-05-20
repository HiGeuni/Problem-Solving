# Enter your code here. Read input from STDIN. Print output to STDOUT

d1 = list(map(int, input().split()))
d2 = list(map(int, input().split()))

def func():
    if d2[2] < d1[2] :
        return 10000
    elif d2[2] == d1[2]:
        if d2[1] < d1[1]:  
            return (d1[1] - d2[1]) * 500    
        elif d2[1] == d1[1] and d2[0] < d1[0]:
            return (d1[0] - d2[0]) * 15 
    return 0
    
print(func())
