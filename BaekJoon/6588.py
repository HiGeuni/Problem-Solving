num = [True] * 1000001
for i in range(2, 1001):
    if num[i] == True:
        for j in range(i+i, 1000001, i):
            num[j] = False
ans = []
for i in range(2,len(num)):
    if num[i] == True:
        ans.append(i)

num[0], num[1] = False, False
while True:
    ipt = int(input())
    if ipt == 0:
        break
    for i in range(ipt, ipt//2-1, -1):
        if num[i] and num[ipt-i]:
            print("{} = {} + {}".format( ipt, ipt-i, i))
            break
