import sys
sys.setrecursionlimit(10**7) #recursionerror 해결

n=int(input())
board=[]
maxHeight=0
for _ in range(n):
    num =list(map(int, input().split()))
    board.append(num)
    for i in num:
        if i > maxHeight:
            maxHeight=i #높이 갱신

dx=[1,0,-1,0] #4방향
dy=[0,1,0,-1]

def dfs(x,y,h):
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<n and 0<=ny<n and not sinked[nx][ny]:
            if board[nx][ny]>h: #현재높이보다 클 때
                sinked[nx][ny]=True
                dfs(nx,ny,h)
ans=0 #최대 영역          
for h in range(maxHeight):
    sinked=[[False]*n for _ in range(n)] #높이별 잠기는 여부
    cnt=0 #잠기지않은 영역
    for j in range(n):
        for k in range(n):
            if board[j][k] >h and not sinked[j][k]:
                cnt+=1
                sinked[j][k]=True
                dfs(j,k,h)
    ans = max(ans, cnt)

print(ans)