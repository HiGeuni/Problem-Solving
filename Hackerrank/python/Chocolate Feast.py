tc = int(input())

for _ in range(tc):
    #ls[0] = Dollars 
    #ls[1] = Dollars A Piece
    #ls[2] = wrappers
    ls = list(map(int, input().split()))
    tnum = ls[0] // ls[1]
    tmp = ls[0]//ls[1]-1
    print(tnum + tmp //(ls[2]-1))
