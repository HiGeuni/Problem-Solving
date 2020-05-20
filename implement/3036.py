#3036 링
#20200405

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

n = int(input())
ls = list(map(int, input().split()))

for i in range(1, n):
    v_gcd = gcd(ls[i], ls[0])
#    print(ls[0]//v_gcd+"/"+ls[i]//v_gcd)
    print('{0}/{1}'.format(ls[0]//v_gcd, ls[i]//v_gcd))
        
