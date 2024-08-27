import sys
input=sys.stdin.readline

n,m,r=map(int, input().split())
data = [list(map(int, input().split())) for _ in range(n)]
def rotate(layer):
    x, y = layer,layer
    temp = data[x][y]
    for j in range(layer+1,n-layer):#왼쪽으로 이동
        x=j
        prev=data[x][y]
        data[x][y]=temp
        temp=prev
    for j in range(layer+1, m-layer):#아래
        y=j
        prev=data[x][y]
        data[x][y]=temp
        temp=prev
    for j in range(layer+1,n-layer):#오른쪽
        x=n-j-1
        prev=data[x][y]
        data[x][y]=temp
        temp=prev
    
    for j in range(layer+1, m-layer):#위
        y=m-j-1
        prev=data[x][y]
        data[x][y]=temp
        temp=prev     

for i in range(min(n,m)//2): #회전횟수 계산
    h=n-2*i
    w=m-2*i
    p=2*(h+w)-4
    rotation = r % p

    for _ in range(rotation):
         rotate(i)
        
for i in range(n):
        print(' '.join(map(str, data[i])))