ar_hour = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve']
ar_minute = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fiften', 'sixteen', 'seventeen', 'eighteen', 'nineteen', 'twenty', 'twenty one', 'twenty two', 'twenty three', 'twenty four', 'twenty five', 'twenty six', 'twenty seven', 'twenty eight', 'twenty nine']

hour = int(input())
minute = int(input())
ans = []

if(minute == 0):
    ans.append(ar_hour[hour-1])
    ans.append(" o' clock")
elif(minute == 1):
    ans.append("one minute past ")
    ans.append(ar_hour[hour-1])
elif(minute >1 and minute <15):
    ans.append(ar_minute[minute-1])
    ans.append(" minutes past ")
    ans.append(ar_hour[hour-1])
elif(minute == 15):
    ans.append("quarter past ")
    ans.append(ar_hour[hour-1])
elif(minute >15 and minute<30):
    ans.append(ar_minute[minute-1])
    ans.append(" minutes past ")
    ans.append(ar_hour[hour-1])
elif(minute == 30):
    ans.append("half past ")
    ans.append(ar_hour[hour-1])
elif(minute>30 and minute<45):
    ans.append(ar_minute[60-minute-1])
    ans.append(" minutes to ")
    ans.append(ar_hour[hour])
elif(minute == 45):
    ans.append("quarter to ")
    ans.append(ar_hour[hour])
elif(minute>45 and minute<60):
    ans.append(ar_minute[60-minute-1])
    ans.append(" minutes to ")
    ans.append(ar_hour[hour])
elif(minute == 59):
    ans.append("one minute to ")
    ans.append(ar_hour[hour])
    
print(''.join(ans))
    
