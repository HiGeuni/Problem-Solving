#Encryption Algorithm/implement
#Medium
#20200218

import math
s = input()

L = len(s)

row = round(math.sqrt(L))

if row >= math.sqrt(L):
    column = row
else:
    column = row +1
    
ls = [[0 for _ in range(column)]for _ in range(row)]
        
idx = 0
for i in range(row):
    for j in range(column):
        if(idx >= L):
            break
        ls[i][j] = s[idx]
        idx+=1

for i in range(column):
    for j in range(row):
        if ls[j][i] == 0:
            continue
        print(ls[j][i], end = '')
    print(end = ' ')
    
