#2644 촌수계산
#20200303

num_people = int(input())
ls = [[1000 for _ in range(num_people)] for _ in range(num_people)]
a,b = map(int, input().split())
num_rel = int(input())
for _ in range(num_rel):
    parent, child = map(int,input().split())
    ls[parent-1][child-1] = 1
    ls[child-1][parent-1] = 1
    
for k in range(num_people):
    for i in range(num_people):
        for j in range(num_people):
            ls[i][j] = min(ls[i][k] + ls[k][j], ls[i][j])

            
if ls[a-1][b-1] == 1000:
    print(-1)
else:
    print(ls[a-1][b-1])
