numList = [4, 7]
for _ in range(4):
    for i in range(len(numList)):
        tmp = numList[i] * 10 + 4
        numList.append(tmp)
        tmp = numList[i] * 10 + 7
        numList.append(tmp)
numList = list(set(numList))
n = int(input())
flag = False
for i in numList:
    if n % i == 0:
        flag = True
        break
print("YES" if flag else "NO")