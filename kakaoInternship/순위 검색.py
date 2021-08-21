from bisect import bisect_left
def solution(info, query):
    answer = []
    dc = {}
    dc["java"] = 1
    dc["python"] = 2
    dc["cpp"] = 3
    dc["backend"] = 4
    dc["frontend"] = 5
    dc["junior"] = 6
    dc["senior"] = 7
    dc["chicken"] = 8
    dc["pizza"] = 9
    dc["-"] = 0
    ls = [[[[[]for i in range(10)] for _ in range(10)] for _ in range(10)]for _ in range(10)]

    for it in info:
        tmp = it.split()
        ls[dc[tmp[0]]][dc[tmp[1]]][dc[tmp[2]]][dc[tmp[3]]].append(int(tmp[4]))
        #하나
        ls[0][dc[tmp[1]]][dc[tmp[2]]][dc[tmp[3]]].append(int(tmp[4]))
        ls[dc[tmp[0]]][0][dc[tmp[2]]][dc[tmp[3]]].append(int(tmp[4]))
        ls[dc[tmp[0]]][dc[tmp[1]]][0][dc[tmp[3]]].append(int(tmp[4]))
        ls[dc[tmp[0]]][dc[tmp[1]]][dc[tmp[2]]][0].append(int(tmp[4]))
        #둘
        ls[0][0][dc[tmp[2]]][dc[tmp[3]]].append(int(tmp[4]))
        ls[0][dc[tmp[1]]][0][dc[tmp[3]]].append(int(tmp[4]))
        ls[0][dc[tmp[1]]][dc[tmp[2]]][0].append(int(tmp[4]))
        ls[dc[tmp[0]]][0][0][dc[tmp[3]]].append(int(tmp[4]))
        ls[dc[tmp[0]]][0][dc[tmp[2]]][0].append(int(tmp[4]))
        ls[dc[tmp[0]]][dc[tmp[1]]][0][0].append(int(tmp[4]))
        #셋
        ls[0][0][0][dc[tmp[3]]].append(int(tmp[4]))
        ls[0][0][dc[tmp[2]]][0].append(int(tmp[4]))
        ls[0][dc[tmp[1]]][0][0].append(int(tmp[4]))
        ls[dc[tmp[0]]][0][0][0].append(int(tmp[4]))
        #넷
        ls[0][0][0][0].append(int(tmp[4]))
    for i in [0,1,2,3]:
        for j in [0,4,5]:
            for k in [0,6,7]:
                for l in [0,8,9]:
                    ls[i][j][k][l].sort()
    for it in query:
        tmp = it.split()
        idx = bisect_left(ls[dc[tmp[0]]][dc[tmp[2]]][dc[tmp[4]]][dc[tmp[6]]], int(tmp[7]))
        answer.append(len(ls[dc[tmp[0]]][dc[tmp[2]]][dc[tmp[4]]][dc[tmp[6]]]) - idx)
    return answer
