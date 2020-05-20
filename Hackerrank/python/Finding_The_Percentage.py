n = int(input())
dic = {}
for _ in range(n):
    name, *score = input().split()
    scores = list(map(float, score))
    dic[name] = scores
    
wonder = input()
ans_ls = dic[wonder]
print("{0:.2f}".format(sum(ans_ls)/3))

#feedback
# how to use *(asterisk)
# list type casting using map
# how to use dictionary
# print format
