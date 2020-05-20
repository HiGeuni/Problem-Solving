#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the birthday function below.
def birthday(s, d, m):
    res =0
    for i in range(len(s)):
        cur_num = 1
        sum_ = s[i]
        if m == cur_num and sum_ == d:
            res+=1
            continue
        for j in range(i+1, len(s)):
            sum_ +=s[j]
            cur_num+=1
            if cur_num > m or sum_ > d:
                break
            if cur_num == m and sum_ == d:
                res+=1
                break
    
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = list(map(int, input().rstrip().split()))

    dm = input().rstrip().split()

    d = int(dm[0])

    m = int(dm[1])

    result = birthday(s, d, m)

    fptr.write(str(result) + '\n')

    fptr.close()
