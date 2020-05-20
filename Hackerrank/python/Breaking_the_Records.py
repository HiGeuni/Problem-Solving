#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the breakingRecords function below.
def breakingRecords(scores):
    min_ans = 0
    max_ans = 0
    min_val = scores[0]
    max_val = scores[0]
    for i in range(1, len(scores)):
        if scores[i] < min_val:
            min_val = scores[i]
            min_ans +=1
        if scores[i] > max_val:
            max_val = scores[i]
            max_ans +=1
    ans = [max_ans, min_ans]
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
