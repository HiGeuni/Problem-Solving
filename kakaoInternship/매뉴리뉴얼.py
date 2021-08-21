from itertools import combinations

def solution(orders, course):
    answer = []
    for num in course:
        candidate = set()
        dc = {}
        ans = 0
        for i in orders:
            for it in combinations(i, num):
                s = ''.join(sorted(it))
                if s not in dc:
                    dc[s] = 1
                else:
                    dc[s] += 1
                    ans = max(ans, dc[s])
                candidate.add(s)
        tmp = []
        for i in candidate:
            if dc[i] == ans:
                tmp.append(i)

        for i in tmp:
            answer.append(i)
    answer.sort()
    return answer
