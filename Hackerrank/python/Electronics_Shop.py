#!/bin/python3

import os
import sys

def getMoneySpent(keyboards, drives, b):
    ans =0
    for k_it in keyboards:
        for d_it in drives:
            if k_it + d_it <=b and ans < k_it + d_it:
                ans = k_it + d_it
    if ans == 0:
        return -1
    else:
        return ans
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    bnm = input().split()

    b = int(bnm[0])

    n = int(bnm[1])

    m = int(bnm[2])

    keyboards = list(map(int, input().rstrip().split()))

    drives = list(map(int, input().rstrip().split()))

    #
    # The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    #

    moneySpent = getMoneySpent(keyboards, drives, b)

    fptr.write(str(moneySpent) + '\n')

    fptr.close()
