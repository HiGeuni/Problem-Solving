#input
n,k = map(int, input().split())

knapsack = [[0]*(k+1) for _ in range(n)]
#solve
for i in range(n):
    weight, value = map(int,input().split())
    
    for j in range(1,k+1):
        if j < weight:
            knapsack[i][j] = knapsack[i-1][j]
        else:
            knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-weight]+value)

print(max(knapsack[-1]))
