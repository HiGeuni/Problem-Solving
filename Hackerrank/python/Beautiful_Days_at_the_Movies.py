# Enter your code here. Read input from STDIN. Print output to STDOUT

i,j,k = map(int,input().split())

ans =0
for date in range(i, j+1):
    if((date - int(str(date)[::-1])) % k == 0):
        ans+=1

print (ans)
