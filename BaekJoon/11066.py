import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    K = int(input())
    C = list(map(int, input().split()))

    d=[[-1 for _ in range(K)] for _ in range(K)]
    for i in range(K):
        d[i][i]=0
    for i in range(K-1):
        d[i][i+1]=C[i]+C[i+1]
    for l in range(3,K+1):
        for i in range(K-l+1):
            j=i+l-1
            tmp=2e9
            for t in range(i,j):
                if tmp > d[i][t]+d[t+1][j]:
                    tmp = d[i][t]+d[t+1][j]
            d[i][j]=tmp+sum(C[i:j+1])
    print(d[0][K-1])
