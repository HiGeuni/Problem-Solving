n = int(input())
INF = 2e9
Card = [0] + list(map(int, input().split()))
P = [0] + [INF]*n

for i in range(1, n+1):
    for j in range(1, i+1):
        P[i] = min(P[i], P[i-j] + Card[j])   
print(P[-1])
