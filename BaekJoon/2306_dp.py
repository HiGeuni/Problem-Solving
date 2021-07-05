import sys
input = sys.stdin.readline

def go(s,e):
    if dp[s][e]!=-1:
        return dp[s][e]
    if s >= e:
        return 0
    if s+1 == e:
        if (ls[s] == 'a' and ls[e] == 't') or (ls[s] == 'g' and ls[e] == 'c'):
            return 2
        else:
            return 0

    tmp = 0

    if (ls[s] == 'a' and ls[e] == 't')  or (ls[s] == 'g' and ls[e] == 'c'):
        tmp = go(s+1, e-1) + 2

    for i in range(s, e):
        tmp = max(tmp, go(s, i) + go(i+1, e))
    dp[s][e] = tmp
    return dp[s][e]

ls = list(input().rstrip())
dp = [[-1 for _ in range(501)] for _ in range(501)]
ans = go(0, len(ls)-1)
print(ans if ans != -1 else 0)