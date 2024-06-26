import sys
input=sys.stdin.readline

stack=[]
k=int(input())

for _ in range(k):
    num = int(input())
    if num != 0:
        stack.append(num)
    else:
        stack.pop()

print(sum(stack))