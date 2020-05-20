#2908 상수
#20200219

a,b = input().split()
if a[::-1] > b[::-1]:
    print(a[::-1])
else:
    print(b[::-1])
