from collections import deque

def solution(queue1, queue2):
    q1Sum = sum(queue1)
    q2Sum = sum(queue2)
    dq1 = deque(queue1)
    dq2 = deque(queue2)
    answer = 0
    
    for _ in range(3*len(queue1)):
        if q1Sum > q2Sum:
            q1Sum -= dq1[0]
            q2Sum += dq1[0]
            t = dq1.popleft()
            dq2.append(t)
        elif q1Sum < q2Sum:
            q1Sum += dq2[0]
            q2Sum -= dq2[0]
            t = dq2.popleft()
            dq1.append(t)
        else:   
            return answer
        answer += 1

    return -1
