#!/bin/python3

import os
import sys

#
# Complete the staircase function below.
#
def staircase(n):
    blank = n-1
    star = 1
    for _ in range(n):
        for _ in range(blank):
            print(" ", end = "")
        for _ in range(star):
            print("#", end = "")
        print()
        blank -=1
        star+=1
    return


if __name__ == '__main__':
    n = int(input())

    staircase(n)
