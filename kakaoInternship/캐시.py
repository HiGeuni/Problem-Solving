def solution(cacheSize, cities):
    answer = 0
    ls = []
    for city in cities:
        city = city.lower()
        if cacheSize == 0:
            answer += 5
            continue
        if city in ls:
            answer += 1
            ls.remove(city)
            ls.append(city)
        else:
            if len(ls) == cacheSize:
                del ls[0]
                ls.append(city)
            else:
                ls.append(city)
            answer += 5

    return answer
