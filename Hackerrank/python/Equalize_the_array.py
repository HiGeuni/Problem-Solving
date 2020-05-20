# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input())
ls = list(map(int, input().split()))

print(len(ls)-max(ls.count(i) for i in ls))
