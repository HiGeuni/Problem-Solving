#1735 분수 합
#20200318

def gcd(a,b):
	if b == 0:
		return a
	return gcd(b, a%b)

a,b = map(int, input().split())
c,d = map(int, input().split())

res_up = b*c+a*d
res_down = b*d

tmp = gcd(res_up, res_down)

print(res_up//tmp, res_down//tmp)
