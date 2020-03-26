#10798 세로 읽기
#20200326 

ls = []
max_len = -1

for _ in range(5):
	tmp = input()
	ls.append(tmp)
	max_len = max(max_len, len(tmp))

for i in range(max_len):
	for j in range(5):
		if len(ls[j]) <= i:
			continue
		print(ls[j][i], end = '')
