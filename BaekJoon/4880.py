#4880 다음수
#20200221
while(1):
	a,b,c = map(int, input().split())
	if a==0 and b== 0 and c==0:
		break
	if 2*b == a+c:
		print("AP", 2*c-b)
		continue
	if c//b == b//a:
		print("GP", c*(b//a))
		continue
