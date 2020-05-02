n = int(input())

ls_cnt = []
ls_name = []

for _ in range(n):
	tmp = input()
	if tmp in ls_name:
		ls_cnt[ls_name.index(tmp)] += 1
	else:
		ls_name.append(tmp)
		ls_cnt.append(0)

ans = []

max_ = max(ls_cnt)

for i in range(len(ls_cnt)):
	if ls_cnt[i] == max_:
		ans.append(ls_name[i])

ans.sort()

print(ans[0])
