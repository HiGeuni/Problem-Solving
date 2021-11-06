n = int(input())
dc = {}
for _ in range(n):
    s = input().rstrip()
    if s not in dc:
        print("OK")
        dc[s] = 0
    else:
        dc[s] += 1
        print('{}{}'.format(s, dc[s]))
