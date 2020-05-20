#https://www.hackerrank.com/challenges/caesar-cipher-1/problem
#Caesar Cipher : Algorithm - String
#20200218
_ = input()
s = input()
k = int(input())
ls = []
for it in s:
    #a == 97
    if(it >='a' and it<='z'):
        print(chr((ord(it)-97+k)%26 + 97), end = '')
    #A = 65
    elif(it>='A' and it <='Z'):
        print(chr((ord(it)-65+k)%26 + 65), end = '')
    else:
        print(it, end = '')
