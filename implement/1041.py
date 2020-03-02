#1041 주사위
#20200302

#최소 값 경우의 수
three =[[0,1,2], [0,1,3], [0,2,4], [1,2,5], [2,4,5], [0,3,4], [3,4,5], [1,3,5]]
two = [[0,1], [0,2], [0,3], [0,4], [1,2], [1,3], [1,5], [2,4], [2,5], [3,4], [3,5], [4,5]]

#input()
n = int(input())
dice = list(map(int, input().split()))

#n == 1인 경우
if n == 1:
    print(sum(dice) - max(dice))
else:
    #각각 한 면이 보이는 주사위, 두 면이 보이는 주사위 개수
    num_one = 4*(n-2)*(n-1) + (n-2)*(n-2)
    num_two = 4*(n-1)+4*(n-2)
    num_three = 4
    #주사위 최댓값 : 50이므로
    ans = [151, 151, 151]
    for i in range(8):
        sum_three = 0
        for j in range(3):
            sum_three += dice[three[i][j]]
        ans[0] = min(ans[0], sum_three)
    for i in range(12):
        sum_two = 0
        for j in range(2):
            sum_two += dice[two[i][j]]
        ans[1] = min(ans[1], sum_two)
    ans[0] *= num_three
    ans[1] *= num_two
    ans[2] = min(dice) * num_one
    print(sum(ans))
