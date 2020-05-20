x1,v1,x2,v2=map(int,input().spit())

res="NO"
 
while(x1>=x2 and v2>v1) or (x2>=x1 and v1>v2):
	if x1==x2:
		res="YES
		break
	x1+=v1
	x2+=v2
	
print(res)
