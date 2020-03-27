#1252.py
#20200327
#int(num, 진수)

n,m = input().split()
n = int(n,2)
m = int(m,2)
print(bin(n+m)[2:])
