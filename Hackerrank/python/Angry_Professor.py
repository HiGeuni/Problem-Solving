# Enter your code here. Read input from STDIN. Print output to STDOUT

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    attendees = n
    a = list(map(int, input().split()))
    for it in a:
        if it>0:
            attendees-=1

    if attendees>=k:
        print('NO')
    else:
        print('YES')
