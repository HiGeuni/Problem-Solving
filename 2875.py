#2875 대회 or 인턴
#20200227
n, m, k = map(int, input().split())

while k!=0:
	if n >= 2*m:
		n-=1
	else:
		m-=1
	k-=1
	
print(min(n//2, m))
