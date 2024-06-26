import sys
n=int(sys.stdin.readline())
stack=[]
def empty(stack):
    return len(stack)==0
for _ in range(n):
    i=sys.stdin.readline().split()
    if i[0]=="1":
        x=i[1]
        stack.append(x)
    elif i[0]=="2":
        if not empty(stack):
            print(stack.pop())
        else:
            print(-1)
    elif i[0]=="3":
        print(len(stack))
    elif i[0]=="4":
        if empty(stack):
            print(1)
        else:
            print(0)
    elif i[0]=="5":
        if not empty(stack):
            print(stack[-1])
        else:
            print(-1) 