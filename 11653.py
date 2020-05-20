#!/usr/bin/python3
#11653 소인수 분해
#20200223

N = int(input())
i =2
while N != 1:
    if N%i == 0:
        N/=i
        print(i)
    else:
        i+=1
