total = int(input())
sum_ = 0
ls = [0 for _ in range(9)]
for i in range(9):
    ls[i] = int(input())
    sum_ += ls[i]
print(total - sum_)
    
