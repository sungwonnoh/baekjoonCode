from collections import deque
n=int(input())
r1,c1,r2,c2=map(int, input().split())
visited=[[0 for _ in range(n)] for _ in range(n)]
dx=[-2,-2,0,0,2,2]
dy=[-1,1,-2,2,-1,1]

def bfs(x,y):
    q=deque([(x,y)])
    visited[x][y]=1
    while q:
        cur_x,cur_y=q.popleft() #현재위치
        if cur_x==r2 and cur_y==c2:
            print(visited[cur_x][cur_y]-1)
            return
        for i in range(6): #방향탐색
            nx, ny= cur_x+dx[i], cur_y+dy[i]
            if 0<=nx<n and 0<=ny<n:
                if visited[nx][ny]==0:
                    q.append((nx,ny))
                    visited[nx][ny]=visited[cur_x][cur_y]+1
    print(-1) #이동할 수 없을때

bfs(r1,c1)