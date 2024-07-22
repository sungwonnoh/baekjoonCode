n=int(input())
board=[]
ans=[]
for _ in range(n):
    board.append(list(map(int, input())))

dx=[1,0,-1,0] #4방향
dy=[0,1,0,-1]
visited=[[False]*n for _ in range(n)]

def dfs(x,y):
    global cnt
    visited[x][y]=True #방문 저장
    cnt+=1
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<n and 0<=ny<n and board[nx][ny]==1 and not visited[nx][ny]:
            dfs(nx,ny) #1인 경우 탐색
result=0
for i in range(n):
    for j in range(n):
        if board[i][j] == 1 and not visited[i][j]: 
            cnt=0 #초기화
            dfs(i,j)
            ans.append(cnt) #집 개수
            result+=1 #단지 개수

ans.sort() #오름차순
print(result)
for i in range(len(ans)):
    print(ans[i])