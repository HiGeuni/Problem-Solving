def gcd(a,b):
    if a%b ==0:
        return b
    else:
        return gcd(b, a%b)

tc = int(input())
ls = []
for _ in range(tc):
    tmp = list(map(int, input().split()))
    sum_ = 0
    for i in range(1,tmp[0]+1):
        for j in range(i, tmp[0]+1):
            if i==j:
                continue
            sum_ += gcd(tmp[i],tmp[j])
            
    print(sum_)
