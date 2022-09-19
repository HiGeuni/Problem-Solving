def nNumber(n, k):
    ls = []
    while n != 0:
        ls.append(n % k)
        n //= k
    return ls[::-1]

def chkPrime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**(1/2))+1):
        if n % i == 0:
            return False
    return True

def solution(n, k):
    answer = 0
    ls = nNumber(n, k)
    tmp = 0
    
    for i in ls:
        if i == 0:
            if chkPrime(tmp):
                answer += 1
            tmp = 0
            
        else:
            tmp *= 10
            tmp += i
            
    if tmp != 0:
        if chkPrime(tmp):
            answer += 1
    
    return answer
