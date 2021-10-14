ls = [int(input()) for _ in range(3)]
l1 = ls[0] + ls[1] + ls[2]
l2 = ls[0] * ls[1] * ls[2]
l3 = ls[0] + ls[1] * ls[2]
l4 = ls[0] * (ls[1] + ls[2])
l5 = (ls[0] + ls[1]) * ls[2]
l6 = ls[0] * ls[1] + ls[2]

print(max(l1, l2, l3, l4, l5, l6))