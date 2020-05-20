#1188 음식 평론가
#2020/02/17

def gcd(a,b):
    if a%b ==0 :
        return b
    return gcd(b, a%b)

n,m= map(int, input().split())
print(m - gcd(n,m))
