 #6359 만취한 상범
 #20020316

tc = int(input()) #test case

for _ in range(tc):
    tmp = int(input())
    #room's status, 0: open 1: closed
    room = [0]*tmp
    for i in range(2,tmp+1):
        for j in range(1, (tmp//i)+1):
            #if the room is closed, open the room
            if room[i*j-1] == 1:
                room[i*j-1] = 0
            else:
                room[i*j-1] = 1
    print(room.count(0))
