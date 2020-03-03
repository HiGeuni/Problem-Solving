#9471 피사노 주기
#20200303

def fisano(n):
    cnt = 1
    fibo1, fibo2 = 1 , 1
    while fibo1 != 0 or fibo2 != 1:
        tmp = fibo1
        fibo1 = fibo2
        fibo2 = (tmp+fibo1) % n
        cnt+=1
        
    return cnt


tc = int(input())
for i in range(tc):
    num, m = map(int, input().split())
    print(num, fisano(m))
