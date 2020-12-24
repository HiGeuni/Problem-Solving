import sys
input = sys.stdin.readline

minus = []
plus = []
zero = []
ans = []

n = int(input())
for _ in range(n):
    tmp = int(input())
    if tmp < 0:
        minus.append(tmp)
    elif tmp == 0:
        zero.append(tmp)
    else:
        plus.append(tmp)

plus = sorted(plus, reverse = True)
minus = sorted(minus)

while True:
    if len(plus) == 0:
        break
    if plus[-1] == 1:
        ans.append(1)
        del plus[-1]
    else:
        break

if len(plus) % 2 == 1:
    ans.append(plus[-1])
    del plus[-1]

if len(minus) % 2 == 1:
    if len(zero) == 0:
        ans.append(minus[-1])
    del minus[-1]
    

for i in range(0, len(plus), 2):
    ans.append(plus[i] * plus[i+1])
    
for i in range(0, len(minus), 2):
    ans.append(minus[i] * minus[i+1])
    
print(sum(ans))
