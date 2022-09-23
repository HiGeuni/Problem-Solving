def solution(gems):
    ansL = 2e9
    answer = []
    dc_cnt = {}
    cnt = 0
    for i in gems:
        if i not in dc_cnt:
            dc_cnt[i] = 0
            cnt += 1
    # init
    l = 0
    r = 0
    dc_cnt[gems[0]] = 1
    aCnt = 1

    while l<=r:
        # 전부 다 찾았으면
        if aCnt == cnt:
            if ansL > r-l:
                answer = [l+1, r+1]
                ansL = r-l
            # 무작정 false로 만들면 안됨
            # 왜냐면 구간에 해당하는 gem이 있을수도 있기 때문에
            dc_cnt[gems[l]] -= 1
            if dc_cnt[gems[l]] == 0:
                # dc[gems[l]] = False
                aCnt -= 1
            l += 1
            continue

        # r을 하나씩 오른쪽으로
        if r < len(gems)-1:
            r += 1
            if dc_cnt[gems[r]] == 0:
                aCnt += 1
                # dc[gems[r]] = True
            dc_cnt[gems[r]] += 1 
        elif gems[l] == gems[r]:
            dc_cnt[gems[l]] -= 1
            l += 1
        
        else:
            dc_cnt[gems[l]] -= 1
            if dc_cnt[gems[l]] == 0:
                # dc[gems[l]] = False
                aCnt -= 1
            l += 1

    # answer = [l+1, r+1]
    return answer
