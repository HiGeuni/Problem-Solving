# Enter your code here. Read input from STDIN. Print output to STDOUT

t = int(input())
for i in range(t):
    n = int(input())
    height = 1
    for i in range(n):
        if i % 2 == 0:
            height *=2
        else:
            height +=1
    print(height)
