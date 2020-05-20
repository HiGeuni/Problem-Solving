# Enter your code here. Read input from STDIN. Print output to STDOUT

_ = input()
s = input()

numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"

n_cnt = 0
l_cnt = 0
u_cnt = 0
s_cnt = 0

for it in s:
    if it in numbers:
        n_cnt +=1
    if it in lower_case:
        l_cnt += 1
    if it in upper_case:
        u_cnt +=1
    if it in special_characters:
        s_cnt+=1

tmp =0

if len(s) <6:
    ans = 6 - len(s)
    if n_cnt == 0:
        tmp += 1
    if l_cnt == 0:
        tmp+=1
    if u_cnt == 0:
        tmp+=1
    if s_cnt == 0:
        tmp+=1
    if tmp > ans:
        ans = tmp

else:   
    ans =0
    if n_cnt == 0:
        ans += 1
    if l_cnt == 0:
        ans+=1
    if u_cnt == 0:
        ans+=1
    if s_cnt == 0:
        ans+=1

print(ans)
