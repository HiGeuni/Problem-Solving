import sys
input = sys.stdin.readline

def is_prime(n):
    if n < 2:
        return False
    i = 2
    while True:
        if i*i > n : break
        if n % i == 0:
            return False
        i += 1
    return True

def dfs(n, num):
    if num == 0:
        print(n)
    for i in range(1, 10, 2):
        tmp = n*10 + i
        if is_prime(tmp):
            dfs(tmp, num-1)

jalitsu = int(input())

ls = [2,3,5,7]
for i in ls:
    dfs(i, jalitsu-1)