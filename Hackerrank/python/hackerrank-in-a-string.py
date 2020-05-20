#https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem
#hackerrank-in-a-string : Algorithms - Strings
#20200218

s1 = ['h','a', 'c', 'k', 'e', 'r', 'r', 'a', 'n', 'k']
n= int(input())
for _ in range(n):
    idx =0
    flag = 0
    s = input()
    for it in s:
        if it == s1[idx] :
            idx+=1
        if idx == 10:
            flag = 1
            break
    if flag ==1:
        print('YES')
    else:
        print('NO')
