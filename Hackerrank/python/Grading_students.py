for i in range(len(grades)):
    ls =[]
    cnt = 0
    for j in range(5):
        if (grades[i]+j)%5==0:
            break
        cnt+=1
    if grades[i]>=38 and cnt<3
        grades[i]+=cnt
    ls.append(grades[i])
return ls
