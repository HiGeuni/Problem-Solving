# Enter your code here. Read input from STDIN. Print output to STDOUT
ls =[]
for i in range(100000):
    ls.append(pow(i, 2))

tc = int(input())

for _ in range(tc):
    ans = 0
    a,b = map(int, input().split())
    for i in range(100000):
        if a<=ls[i] and ls[i]<=b:
            ans+=1
        elif ls[i] > b:
            break
    print(ans)
