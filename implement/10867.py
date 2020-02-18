#10867 중복 빼고 정렬하기
#20200218

n = int(input())
ls = set(map(int, input().split()))

for it in sorted(list(ls)):
    print(it, end =' ')
    
