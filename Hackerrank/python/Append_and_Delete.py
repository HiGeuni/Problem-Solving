s = input()
t = input()
k = int(input())

common = 0

sum_st = len(s) + len(t)
for i in range(min(len(s), len(t))):
    if s[i] == t[i]:
        common+=1
    else:
        break

if (sum_st- 2*common) > k :
    print("No")
elif ((sum_st - 2*common)%2) == (k%2):
    print("Yes")
elif (sum_st - k) < 0:
    print("Yes")
else:
    print("No")

