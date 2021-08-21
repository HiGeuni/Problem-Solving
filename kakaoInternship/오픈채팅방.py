def solution(record):
    tmp = []
    for i in record:
        tmp.append(i.split())
    answer = []
    dc = dict()
    for rec in tmp:
        if rec[0] == "Enter":
            dc[rec[1]] = rec[2]
        elif rec[0] == "Change":
            dc[rec[1]] = rec[2]
    for rec in tmp:
        if rec[0] == "Enter":
            answer.append(dc[rec[1]]+"님이 들어왔습니다.")
        elif rec[0] == "Leave":
            answer.append(dc[rec[1]]+"님이 나갔습니다.")

    return answer
