import sys
input = sys.stdin.readline

s = list(input().rstrip())
st = []
flag = 0
operation = ['+','-','*','/','(',')']

#  1. 우선순위 파악하기
for i in range(len(s)):
    if s[i] not in operation:
        print(s[i],end = '')
    else:
        if s[i] == '(':
            st.append(s[i])
        elif s[i] == ')':
            flag -= 1


