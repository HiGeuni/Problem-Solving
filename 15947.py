#15947 아기 석환 뚜루루 뚜루
#20200227

ls = ['baby', 'sukhwan', 'tururu', 'turu', 'very', 'cute', 'tururu', 'turu', 'in', 'bed', 'tururu', 'turu', 'baby', 'sukhwan']
n = int(input())
idx = (n-1)%14
cnt = n//14
if ls[idx] == 'tururu':
	if cnt > 2:
		print('tu+ru*%s'%(cnt+2))
	else:
		print(ls[idx]+"ru"*(n//14))
		
elif ls[idx] == 'turu':
	if cnt > 3:
		print('tu+ru*%s'%(cnt+1))
	else:
		print(ls[idx]+"ru"*(n//14))
else:
	print(ls[idx])
