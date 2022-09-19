import math

# a : outTime, b : inTime
def calTime(a, b):
    if a[1] < b[1]:
        t = 60 - (b[1] - a[1])
        a[0] -= 1
    else:
        t = a[1] - b[1]
    t += (a[0] - b[0]) * 60
    return t

def solution(fees, records):
    a,b,c,d = fees
    answer = []
    dc = {}
    for record in records:
        info = record.split()
        h, m = map(int, info[0].split(":"))
        number = info[1]
        if info[2] == "IN":
            if info[1] in dc:
                cumul = dc[info[1]][4]
            else:
                cumul = 0
            dc[info[1]] = [h, m, 0, True, cumul]
        else:
            e = calTime([h, m], dc[info[1]][:2])
            dc[info[1]][4] += e
            dc[info[1]][3] = False
            
    sd = sorted(dc.items())
    for key in sd:
        if key[1][3]:
            e = calTime([23, 59], key[1][:2])
            key[1][4] += e
        if key[1][4] <= a:
            key[1][2] += b
        else:
            print(key[1][4], a, math.ceil((key[1][4] - a)/c))
            key[1][2] += (b + (math.ceil((key[1][4]-a)/c)) * d)
        answer.append(key[1][2])
    return answer
