apple_res=0
orange_res=0


for i in range(len(apples)):
	if a+apples[i]>=s and a+apples[i]<=t:
		apple_res+=1

for i in range(len(oranges)):
	if b+oranges[i]>=s and b+oranges[i]<=t:
		orange_res+=1

print(apple_res)
print(orange_res)
