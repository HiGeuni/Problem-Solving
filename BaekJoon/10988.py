#10988 펠린드롬인지 확인하기
#20200318

st = input()

flag = True

leng = len(st)

for i in range(leng//2):
	if st[i] != st[leng-i-1]:
		flag = False
		break
	
if flag:
	print(1)
else:
	print(0)
