import sys
input = sys.stdin.readline

MOD = 1000000

cipher = input().rstrip()

t = len(cipher)

dp = [1] + [0 for _ in range(t)]

if cipher[0] == '0':
    print(0)
else:
    cipher = '0' + cipher
    for i in range(1, t+1):
        if cipher[i] != '0':
            dp[i] = (dp[i] + dp[i-1]) % MOD
        if i >= 2:
            t = cipher[i-1:i+1]
            if 10<=int(t)<=26:
                dp[i] = (dp[i] + dp[i-2]) % MOD
    print(dp[-1])
