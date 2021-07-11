import sys
input = sys.stdin.readline

N = int(input())
ta, tb = map(int,input().split())
l=0
r=0
tta = ta
ttb = tb
for _ in range(1, N):
    tmpA, tmpB = map(int,input().split())
    l += ta*tmpB
    r += tb*tmpA
    ta = tmpA
    tb = tmpB
l += ta * ttb
r += tb * tta
print(((round(abs(l-r)/2*100)//10)/10))
