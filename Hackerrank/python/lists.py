if __name__ == '__main__':
    N = int(input())

ls = []

for _ in range(N):
    instruction, *arg = input().split()
    cmd = "ls." + instruction +'('
    if len(arg)==2:
        cmd = cmd + arg[0] +',' + arg[1]
    elif len(arg)==1:
        cmd = cmd + arg[0]
    cmd = cmd + ')' 
    if instruction == "print":
        print(ls)
    else:
        eval(cmd)

#How to use eval
#string +
