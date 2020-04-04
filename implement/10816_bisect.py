#10816 카드 놀이 2
#20200404

import bisect

n = int(input())
arr = sorted(list(map(int, input().split())))
m = int(input())
s_arr = list(map(int, input().split()))

for it in s_arr:
    i1 = bisect.bisect_left(arr, it)
    if i1 < len(arr) and arr[i1] == it:
        i2 = bisect.bisect_left(arr, it+1)
        print(i2 - i1, end = ' ')
    else:
        print(0, end = ' ')
