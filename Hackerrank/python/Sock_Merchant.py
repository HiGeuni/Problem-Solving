# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input())
ar = list(map(int, input().split()))
color_list = []
ans = 0

for i in range(n):
    if ar[i] not in color_list:
        color_list.append(ar[i])
for i in range(len(color_list)):
    ans+= int(ar.count(color_list[i])/2)

print(int(ans))
