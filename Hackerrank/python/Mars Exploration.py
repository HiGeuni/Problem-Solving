# https://www.hackerrank.com/challenges/mars-exploration/problem
# Mars Exploration : Algoritms - Strings
#20200218

s=input()
#0 : S, 1 : O, 2 : S
SOS = ['S', 'O', 'S']
ans = 0
for i in range(len(s)):
    if s[i] != SOS[i%3]:
        ans+=1
print(ans)
