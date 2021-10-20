ls = []
for i in range(1000):
    t = 180 * i
    tm = 180 * i // (i+2)
    if 180 *i % (i+2) == 0:
        ls.append(tm)
        if tm == 179:
            break

for _ in range(int(input())):
    n = int(input())
    print("YES" if n in ls[1:] else "NO")
