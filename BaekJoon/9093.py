n = int(input())

for _ in range(n):
    st = []
    res = ''
    string = input()
    
    for i in string:
        if i == ' ':
            while st:
                res += st.pop()
            res += ' '
        else:
            st.append(i)
            
    while st:
        res += st.pop()
    
    print(res)
