from bisect import bisect_left

n = int(input())
ls = [list(map(int,input().split())) for _ in range(n)]
ls.sort(key=lambda x : x[0])
# print(ls)
ans = [ls[0][1]]
for i, j in ls:
    # print(ans, j)
    if ans[-1] < j:
        ans.append(j)
    else:
        idx = bisect_left(ans, j)
        ans[idx] =j
print(len(ls) - len(ans))
