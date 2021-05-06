from itertools import permutations
import math
oper = ["*", "+", "-"]
num = []
op = []

def calculate(pri):
    tmpNum = num[:]
    tmpOp = op[:]
    order = []
    for i in range(3):
        order.append(oper[pri.index(i)])
    
    orderIdx = 0
    
    while len(tmpOp) != 0:
        cnt = 0
        tmpSize = len(tmpOp)
        for i in range(tmpSize):
            if tmpOp[i-cnt] == order[orderIdx]:
                a = tmpNum[i-cnt]
                b = tmpNum[i-cnt+1]
                
                del tmpNum[i-cnt]
                del tmpNum[i-cnt]
                
                if order[orderIdx] == "*":
                    tmpNum.insert(i-cnt, a*b)
                elif order[orderIdx] == "+":
                    tmpNum.insert(i-cnt, a+b)
                else:
                    tmpNum.insert(i-cnt, a-b)
                    
                del tmpOp[i-cnt]
                cnt += 1
            else:
                continue
        if cnt == 0:
            orderIdx += 1
            if orderIdx == 3:
                break
            
    return abs(tmpNum[0])
    

def solution(exp):
    answer = -2e9
    tmp = ""

    for i in range(len(exp)):
        if exp[i] in oper:
            if tmp != "":
                num.append(int(tmp))
                tmp = ""
            op.append(exp[i])
        else:
            tmp += exp[i]
    num.append(int(tmp))
    for it in permutations(range(0, 3)):
        answer = max(answer, calculate(list(it)))
    
    return answer
