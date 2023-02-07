import sys
input = sys.stdin.readline

N = int(input())

ls = sorted(list(map(int,input().split())))

ans = 0

for i in range(len(ls)):
  t = ls[:i] + ls[i+1:]
  l = 0
  r = len(t)-1

  
  
  while l < r:
      tmp = t[l] + t[r]
      if tmp == ls[i]:
          ans += 1
          break
      if ls[i] > tmp:
          l += 1
      else:
          r -= 1
print(ans)
