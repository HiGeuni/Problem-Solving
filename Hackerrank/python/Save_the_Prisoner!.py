# Enter your code here. Read input from STDIN. Print output to STDOUT
tc = int(input())
for _ in range(tc):
    n, m, s = map(int, input().split())
    m = m%n
    ans = (m+s-1)%n
    if ans == 0:
        ans = n

    print(ans)
