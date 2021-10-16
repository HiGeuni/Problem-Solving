for _ in range(int(input())):
    n = int(input())
    s = input().rstrip()
    tmp = 0
    ans = 0
    for i in s:
        if i == '(':
            tmp += 1
        else:
            tmp -= 1
            if tmp < 0:
                tmp = 0
                ans += 1
    print(ans)
