# Enter your code here. Read input from STDIN. Print output to STDOUT

s = input()

ans = 1
for it in s:
    if it>='A' and it <='Z':
        ans +=1
print(ans)
