def solution(str1, str2):
    answer = 0
    str1 = str1.lower()
    str2 = str2.lower()
    setA = []
    setB = []
    for i in range(len(str1)-1):
        ta = str1[i:i+2]
        flag = True
        for j in range(2):
            if not ta[j].isalpha():
                flag = False
        if flag:
            setA.append(ta)
            
    for i in range(len(str2) -1):
        tb = str2[i:i+2]
        flag = True
        for j in range(2):
            if not tb[j].isalpha():
                flag = False
        if flag:
            setB.append(tb)
    
    setA_copy = setA.copy()
    setB_copy = setB.copy()

    inter_ = []
                
    for i in setA:
        if i in setB_copy:
            inter_.append(i)
            setA_copy.remove(i)
            setB_copy.remove(i)

    sum_ = setA_copy + setB_copy + inter_        
    print(sum_, inter_)
    if len(sum_) == 0:
        answer = 65536
    else:
        answer = int(len(inter_) / len(sum_) * 65536)


    return answer
