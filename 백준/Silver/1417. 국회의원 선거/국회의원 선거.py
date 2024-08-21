n=int(input())
arr=[]
cnt=0
num1=int(input())
for _ in range(n-1):
    arr.append(int(input()))
arr.sort(reverse=True) #내림차순 정렬

if n==1:
    print(0)
else:
    while arr[0]>=num1: #기호 1번보다 값이 크면
        arr[0]-=1
        num1+=1
        cnt+=1
        arr.sort(reverse=True)
    print(cnt)