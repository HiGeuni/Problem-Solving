#10612 전자레인지
#20200218

button = [300, 60, 10]
num = [0,0,0]
n = int(input())
if(n%10 !=0):
    print(-1)
else:
    if(n>=button[0]):
        num[0] = n//button[0]
        n -= num[0] * button[0]
    if(n>=button[1]):
        num[1] = n//button[1]
        n -= num[1] * button[1]
    if(n>=button[2]):
        num[2] = n//button[2]
        n -= num[2] * button[2]

    for i in range(3):
        print(num[i], end = ' ')
