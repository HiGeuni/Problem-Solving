# 분할정복
# 1. 십진수 -> 이진수로 변환
#  

def chk(s):
    print(s)
    if len(s) == 1:
        return True
    if int(s) == 0:
        return True
    if s[len(s)//2] != '1':
        return False
    else:
        return chk(s[:len(s)//2]) and chk(s[len(s)//2+1:])
    

l = [pow(2, i)-1 for i in range(8)]

def solution(numbers):
    answer = []
    for i in numbers:
        b = bin(i)[2:]
        bl = 0
        for num in range(8):
            if len(b) <= l[num]:
                bl = num
                break
        b = ''.join('0' for _ in range(l[bl] - len(b))) + b
        answer.append(1 if chk(b) else 0)
        # chk
    return answer

print(solution([63, 111, 95, 5, 7]))
