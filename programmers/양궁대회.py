# 첫 번째 접근
# 1발에 몇 점의 이득을 가지나?
# 상대가 한 발 이상 맞췄을 때, 해당 점수 * 2 / 화살 개수
# 그렇지 않을 때 -> 그 점수 그대로
# [과녁 점수, 화살 개수, cost]
# n : 화살의 개수, info : 상대가 얼마나 맞췄는지
# 왜 틀렸지?

# def solution(n, info):
#     answer = [0 for _ in range(11)]
#     score = [0,0]
#     ls = []
    
#     for i in range(len(info)):
#         if info[i] == 0:
#             ls.append([10-i, info[i] + 1, 10-i])
#         else:
#             score[0] += 10-i
#             ls.append([10-i, info[i] + 1, 2 * (10-i) / (info[i] + 1)])
            
#     ls = sorted(ls, key = lambda item: item[2], reverse=True)
    
    
#     for l in ls:
#         # 쏠 수 있는 경우
#         if n >= l[1]:
#             n -= l[1]
#             score[1] += l[0]
#             answer[10 - l[0]] = l[1]
#             if l[1] != 1:
#                 score[0] -= l[0]
    
#     # 남은 화살 처리
#     if n != 0:
#         answer[10] = n
    
#     if score[0] >= score[1]:
#         return [-1]
#     else:
#         return answer


# 두 번째 접근
# 완전 탐색
# 경우의 수가 n개의 화살
from itertools import combinations_with_replacement

def solution(n, info):
    gap = 0
    answer = [-1]
    for cwr in combinations_with_replacement(list(range(11)), n):
        t = [0 for _ in range(11)]
        for score in cwr:
            t[10-score] += 1
            
        # 비교
        a = 0
        b = 0
        
        for i in range(11):
            if not info[i] and not t[i]:
                continue
            if info[i] >= t[i]:
                a += (10-i)
            else:
                b += (10-i)
                
        tmp_gap = b-a
        
        if tmp_gap > gap:
            gap = tmp_gap
            answer = t

    return answer
