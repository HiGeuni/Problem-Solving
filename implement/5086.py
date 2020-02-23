#python3 
#5086 배수와 약수
#20200223

def is_factor(a,b):
    if b%a == 0:
        return 1
    return 0
    
def is_multiple(a,b):
    if a%b == 0:
        return 1
    return 0
    
while(1):
    n,m = map(int, input().split())
    if n==0 and m==0:
        break
    if is_factor(n,m) == 1:
        print('factor')
    elif is_multiple(n,m) == 1:
        print('multiple')
    else:
        print('neither')
