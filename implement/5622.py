sum = 0
for it in input():
	if it in ['A', 'B', 'C']:
		sum+=3
	elif it in ['D', 'E', 'F']:
		sum+=4
	elif it in ['G', 'H', 'I']:
		sum+=5
	elif it in ['J', 'K', 'L']:
		sum+=6
	elif it in ['M', 'N', 'O']:
		sum+=7
	elif it in ['P', 'Q', 'R', 'S']:
		sum+=8
	elif it in ['T', 'U', 'V']:
		sum+=9
	elif it in ['W', 'X', 'Y', 'Z']:
		sum+=10
	else:
		sum+=11
print(sum)
