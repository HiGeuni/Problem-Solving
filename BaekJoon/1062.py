import sys
from itertools import combinations
input = sys.stdin.readline

n,m = map(int,input().split())

t = [0 for _ in range(n)]

for i in range(n):
    s = input().rstrip()
    for j in range(len(s)):
        t[i] |= 1<<(ord(s[j]) - ord('a'))
if m < 5:
    print(0)
else:
    tmpLs = [i for i in range(26)]
    set1 = set(list(chr(i) for i in range(97, 123)))
    set2 = set(['a','n','c','i','t'])
    set1 = list(set1-set2)
    ans =0
    for it in combinations(set1, m-5):
        bit = 532741
        cnt = 0
        for j in it:
            bit |= 1<<(ord(j) - ord('a'))
        for i in range(n):
            if t[i] & bit == t[i]:
                cnt += 1
        ans = max(ans, cnt)
    print(ans)
