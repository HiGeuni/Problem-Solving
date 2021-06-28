import sys
input = sys.stdin.readline

while True:
    try:
        x = int(input())*10000000
        num = int(input())
        ls = sorted([int(input()) for _ in range(num)])
        l = 0
        r = num - 1
        flag = False
        while l < r:
            tmp = ls[l] + ls[r]
            if tmp > x:
                r -= 1
            elif tmp < x:
                l += 1
            elif tmp == x:
                flag = True
                print("yes", ls[l], ls[r])
                break
        if not flag:
            print("danger")
    except:
        break