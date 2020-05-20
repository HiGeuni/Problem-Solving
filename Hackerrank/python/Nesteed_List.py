#input
n = int(input())
ls = [[input(), float(input())] for _ in range(n)]
#first time, I write the code "ls = ([input(), float(input())] for _ in range(n)]

#how_to_solve
second_lowest = sorted(list(set([score for name, score in ls])))[1]

print('\n'.join([name for name, score in sorted(ls) if score == second_lowest])) 

