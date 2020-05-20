#!/bin/python3

import os
import sys

#
# Complete the miniMaxSum function below.
#
def miniMaxSum(arr):
    Sum =0
    for i in range(len(arr)):
        Sum += arr[i]
    print(Sum - arr[4], end = " ")
    print(Sum - arr[0])
    return

if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))
    arr.sort()
    miniMaxSum(arr)
