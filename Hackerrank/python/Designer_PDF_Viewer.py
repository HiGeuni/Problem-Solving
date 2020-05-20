# Enter your code here. Read input from STDIN. Print output to STDOUT

alphabet = list(map(int, input().split()))
s = input()

h_max = 0

for it in s:
    h_max = max(h_max, alphabet[ord(it) - ord('a')])

print(len(s) * h_max)
