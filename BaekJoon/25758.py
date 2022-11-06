import sys
input = sys.stdin.readline

dc = {}

t = []

for i in range(26):
    for j in range(26):
        dc[chr(65 + i)+chr(65 + j)] = 0
        t.append(chr(65 + i)+chr(65 + j))
        
n = int(input())
s = list(input().split())

candidate = []

for i in s:
    dc[i] += 1

for i in range(len(t)):
    for j in range(i, len(t)):
        if i == j:
            if dc[t[i]] >= 2:
                a = max(t[i][0], t[i][1])
                if a not in candidate:
                    candidate.append(a)
        elif dc[t[i]] >= 1 and dc[t[j]] >=1:
            a = max(t[i][0], t[j][1])
            b = max(t[i][1], t[j][0])
            if a not in candidate:
                candidate.append(a)
            if b not in candidate:
                candidate.append(b)

print(len(candidate))
print(*sorted(candidate))
