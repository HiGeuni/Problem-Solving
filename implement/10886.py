#10886 0 = not cute / 1 = cute
#20200325

n = int(input())
cnt = [0,0]
for i in range(n):
	tmp = input()
	if tmp == '0':
		cnt[0] +=1
	else:
		cnt[1] +=1

if cnt[0]>cnt[1] :
	print("Junhee is not cute!")
else:
	print("Junhee is cute!")
