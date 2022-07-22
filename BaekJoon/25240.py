import sys
input = sys.stdin.readline

auth = {
    "X" : 1,
    "W" : 2,
    "R" : 4
}

user = {}
file_ = {}

U, F = map(int, input().split())

for j in range(U):
    a = input().rstrip().split()
    user[a[0]] = []

    if len(a) == 2:
        grp = a[1].split(',')
        for i in grp:
            user[a[0]].append(i)
    user[a[0]].append(a[0])

for i in range(F):
    info = list(input().split())
    file_[info[0]] = info[1:]

q = int(input())

for _ in range(q):
    name, fname, perm = input().split()
    p = file_[fname][0]
    if name == file_[fname][1]:
        if int(p[0]) & auth[perm]:
            print(1)
            continue
    flag = False
    for i in user[name]:
        if i == file_[fname][2]:
            if int(p[1]) & auth[perm]:
                print(1)
                flag = True
                break
    if flag:
        continue

    if int(p[2]) & auth[perm]:
        print(1)
        continue
    print(0)
