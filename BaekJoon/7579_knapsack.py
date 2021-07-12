import sys
input = sys.stdin.readline

N,M = map(int,input().split())
memory = list(map(int,input().split()))
cost = list(map(int,input().split()))
knapsack = [[0 for _ in range(sum(cost) + 1)] for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(sum(cost), -1, -1):
        if j >= cost[i-1]:
            knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-cost[i-1]] + memory[i-1])
        else:
            knapsack[i][j] = knapsack[i-1][j]
for i in range(sum(cost)+1):
    if knapsack[N][i] >= M:
        print(i)
        break