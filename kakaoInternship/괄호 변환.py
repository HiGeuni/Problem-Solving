def isBalance(s):
    lCnt = 0
    rCnt = 0
    for i in s:
        if i == '(':
            lCnt += 1
        else:
            rCnt += 1
    return lCnt == rCnt

def isCorrect(s):
    if s == '':
        return False
    st = []
    flag = True
    for i in s:
        if len(st) == 0:
            if i == ')':
                flag = False
                break
            else:
                st.append(i)
        elif i == '(':
            st.append(i)
        else:
            if st[-1] == '(':
                st = st[:-1]
            else:
                flag = False
                break
    if len(st) != 0:
        flag = False
    return flag

def recur(s):
    ans = ''
    if s == '':
        return ''
    u = ''
    v = ''
    for i in range(1, len(s)+1):
        u = s[:i]
        v = s[i:]
        if isBalance(u):
            break
    if isCorrect(u):
        ans = u + recur(v)
    else:
        tmp = '('
        tmp += recur(v)
        tmp += ')'
        u = u[1:]
        u = u[:-1]
        newU = ''
        for i in range(len(u)):
            if u[i] == "(":
                newU += ")"
            else:
                newU += "("
        ans = tmp + newU
    return ans



def solution(p):
    answer = ''
    if isCorrect(p):
        return p
    answer = recur(p)
    return answer
