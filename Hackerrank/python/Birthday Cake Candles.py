#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the birthdayCakeCandles function below.
def birthdayCakeCandles(ar):
    cnt = 0
    max_num = ar[len(ar)-1]
    for i in range(len(ar)):
        if(max_num == ar[i]):
            cnt+=1
    return cnt


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    ar.sort()

    result = birthdayCakeCandles(ar)

    fptr.write(str(result) + '\n')

    fptr.close()
