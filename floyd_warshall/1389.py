# 1389 케빈 베이컨의 6단계 법칙
#20200229

#input
n,m = map(int, input().split())

#initialize the list
user = [[n for _ in range(n)] for _ in range(n)]

#input
for _ in range(m):
    a,b = map(int, input().split())
    user[a-1][b-1] = 1
    user[b-1][a-1] = 1
    
#floyd_warshall
for k in range(n):
    for i in range(n):
        for j in range(n):
            if i == j:
                user[i][j] = 0
            else:
                user[i][j] = min(user[i][k] + user[k][j], user[i][j])   
#solve
ans = []
for a in user:
    ans.append(sum(a))
    
print(ans.index(min(ans))+1)
