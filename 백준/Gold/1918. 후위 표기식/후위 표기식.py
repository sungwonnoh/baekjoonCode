stack = []
answer =''
line = input()
for i in line:
    if i.isalpha():  # 문자인 경우 (피연산자)
        answer += i
    elif i == '(':
        stack.append(i)
    elif i =='*' or i =='/':
        while stack and (stack[-1]=='*' or stack[-1]=='/'):
            answer += stack.pop()
        stack.append(i)
    elif i =='+' or i =='-':
        while stack and stack[-1] != '(' and (stack[-1]=='+' or stack[-1]=='-' or stack[-1]=='*' or stack[-1]=='/'):
            answer += stack.pop()
        stack.append(i)
    elif i == ')':
        while stack and stack[-1] != '(':
            answer += stack.pop()
        stack.pop()

while stack:
    answer += stack.pop()

print(answer)