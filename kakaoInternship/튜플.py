def solution(s):
    answer = []
    #extract array

    use = []
    st = []
    tmp = []
    num = 0
    for i in s:
        if i == '{':
            st.append(i)
        elif i == '}':
            if num != 0:
                tmp.append(num)
                use.append(tmp)
                tmp = []
                num = 0
            st.pop()
        elif i == ',':
            if len(st) == 1:
                continue
            else:
                tmp.append(num)
                num = 0
        else:
            num *= 10
            num += int(i)
    use.sort(key=len)
    dc = {}
    for i in range(len(use)):
        for j in range(len(use[i])):
            if use[i][j] in dc:
                continue
            else:
                answer.append(use[i][j])
                dc[use[i][j]] = 1
    return answer
