#2775 부녀회장이 될테야
#20200219

tc = int(input())
for _ in range(tc):
    k = int(input())
    n = int(input())
    ar = [ i for i in range(1, n+1)]
    for _ in range(k):
        for j in range(1,n):
            ar[j] += ar[j-1]
    print(ar[-1])

    
