#2960 에라토스테네스의 체
#20200325

n, k = map(int, input().split())
ls = [0 for _ in range(n+1)]

cnt =1

for i in range(2, n+1):
	if ls[i] == 0:
		for j in range(i, n+1, i):
			if ls[j] == 1:
				continue
			if cnt == k:
				print(j)
			ls[j] = 1
			cnt+=1
