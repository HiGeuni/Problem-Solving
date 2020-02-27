# 16433 주디와 당근농장
# 20200226

N, R, C = map(int,input().split())

if (R + C) % 2 == 0:
    for i in range(N):
        if i % 2 == 0:
            print("v." * (N // 2) + 'v' * (N % 2))
        else:
            print(".v" * (N // 2) + '.' * (N % 2))
            
else:
    for i in range(N):
        if i % 2 == 1:
            print("v." * (N // 2) + 'v' * (N % 2))
        else:
            print(".v" * (N // 2) + '.' * (N % 2))
