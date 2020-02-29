#10773 제로
#20200229

#input
k = int(input())
num = [] #stack

#solve the problem
for _ in range(k):
    a = int(input()) #input num
    if a==0: 
        #stack.pop()
        del num[len(num)-1]
    else:
        #stack.push(a)
        num.append(a)

#output
print(sum(num))
