#11866 요세푸스 문제 0
#20200302

n,k = map(int, input().split())
seq = [a for a in range(1, n+1)]
res = []
i=k-1
while True:
    res.append(seq.pop(i))
    if len(res) == n:
        break
    i = (i+k-1) % len(seq)

print('<'+', '.join(map(str, res))+'>')
