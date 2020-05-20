#17173 배수들의 합
#20200318
n, m = map(int, input().split())
k = list(map(int, input().split()))
ls = []

for i in range(1, n+1):
	for j in k:
		if i%j == 0 and i not in ls:
			ls.append(i)
print(sum(ls))
