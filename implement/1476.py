#1476 날짜 계산
#20200306

e,s,m = map(int, input().split())

tmp = [1,1,1]

ans = 1

while True:
    if tmp[0] == e and tmp[1] == s and tmp[2] == m:
        break
    for i in range(3):
        tmp[i] += 1
    ans += 1
    if tmp[0] > 15:
        tmp[0] = 1
    if tmp[1] > 28:
        tmp[1] = 1
    if tmp[2] > 19:
        tmp[2] = 1
    
print(ans)
