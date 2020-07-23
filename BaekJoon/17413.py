st = []
res = ''
tag = False
string = input()
for i in string:
    if tag:  # tag가 열렸을때
        res += i
        if i == '>':
            tag = False
    else:
        if i == '<':
            tag = True
            while st:
                res += st.pop()    
            res+=i  
        elif i == ' ':
            while st:
                res += st.pop()
            res += ' '
        else:
            st.append(i)

while st:
    res+=st.pop()
print(res)
