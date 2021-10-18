n = int(input())
ls = [0 for _ in range(5)]
t = list(map(int,input().split()))
for i in t:
    ls[i] += 1
ls[1] = max(ls[1] - (ls[2]%2)*2 - ls[3], 0)
print((ls[1]//4 + 1 if ls[1]%4 != 0 else ls[1]//4) + (ls[2]//2 + 1 if ls[2]%2 != 0 else ls[2]//2) + ls[3] + ls[4])
