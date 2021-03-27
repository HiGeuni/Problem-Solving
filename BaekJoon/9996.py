import sys
input = sys.stdin.readline

n = int(input())
ta = input().rstrip()
pattern = ta.split('*')
for _ in range(n):
    tmp = input().rstrip()
    if tmp[:len(pattern[0])] == pattern[0] and tmp[-len(pattern[1]):] == pattern[1] and len(tmp) >= len(ta)-1:
        print("DA")
    else:
        print("NE")