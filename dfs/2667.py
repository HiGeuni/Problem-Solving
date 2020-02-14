#2667 단지번호 붙이기

def dfs(x,y,depth):
    if ls[x][y] == 0: 
        return
    if visited[x][y] !=0:
        return
    visited[x][y] = depth
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if nx<n and ny<n and nx>=0 and ny>=0:
            dfs(nx, ny, depth)
    return

ls = []
n = int(input())
visited = [[0 for _ in range(n)] for _ in range(n)]
dx = [0,0,1,-1]
dy = [1,-1, 0,0]
depth = 0

for _ in range(n):
    ls.append(list(map(int, str(input()))))
    
for i in range(n):
    for j in range(n):
        if ls[i][j] == 1 and visited[i][j] ==0:
            depth +=1
            dfs(i, j, depth)

print(depth)
ans = [0 for _ in range(depth)]

for i in range(1, depth+1):
    for j in range(n):
        ans[i-1] += visited[j].count(i)

for num in sorted(ans):
    print(num)
