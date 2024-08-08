from collections import deque
n,m=map(int, input().split())
board=[]
dx=[1,1,0,-1,-1,-1,0,1]
dy=[0,1,1,1,0,-1,-1,-1]

visited=[[0 for _ in range(m)] for _ in range(n)]
for _ in range(n):
    board.append(list(map(int, input().split())))

def bfs():
    q=deque()
    for i in range(n):
        for j in range(m):
            if board[i][j]==1: #1의 위치 추가
                q.append((i,j))
                visited[i][j]=1
    ans=0
    while q:
        x,y=q.popleft()
        for i in range(8):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<m and visited[nx][ny]==0: #범위내에 있거나 방문하지않았을 때
                q.append((nx,ny))
                visited[nx][ny]=visited[x][y]+1
                ans=max(ans, visited[nx][ny])
    return ans-1

print(bfs())