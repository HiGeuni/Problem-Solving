# Enter your code here. Read input from STDIN. Print output to STDOUT
def fibonacci(n):
    if dp[n] is not -1:
        return dp[n]
    dp[n] = fibonacci(n-2)+pow(fibonacci(n-1),2)
    return dp[n]

t1, t2, n = map(int, input().split())
dp = list(-1 for _ in range(n))
dp[0] = t1
dp[1] = t2
print(fibonacci(n-1))
