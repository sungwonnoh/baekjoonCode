n=int(input())
a=[[0]*10 for _ in range(n)]

a[0]=[0,1,1,1,1,1,1,1,1,1] #시작숫자

for i in range(1,n):
    a[i][0]=a[i-1][1] #1-0
    a[i][9]=a[i-1][8] #9-8
    for j in range(1,9):
        a[i][j]=a[i-1][j-1]+a[i-1][j+1]

print(sum(a[n-1])% 1000000000) 