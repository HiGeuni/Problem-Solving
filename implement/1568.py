#1568 새
#20200318

n = int(input())
day = 1
i=1
while n != 0:
	if i > n:
		i = 1
	n -= i
	i+=1
	day+=1
	
print(day-1)
