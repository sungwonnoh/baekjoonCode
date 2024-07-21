import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
dx=[1,1,0,-1,-1,-1,0,1] #동서남북+대각선 방향
dy=[0,1,1,1,0,-1,-1,-1]

def dfs(x,y):
    visited[x][y]=True #방문여부 저장
    for i in range(8):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<h and 0<=ny<w and board[nx][ny]==1 and not visited[nx][ny]:
            dfs(nx,ny)

while True:
    w,h = map(int, input().split())
    if w==0 and h==0: #0 0 일때 입력중단
        break
    board=[] #지도 초기화
    for _ in range(h):
        board.append(list(map(int, input().split())))
    visited = [[False] * w for _ in range(h)] #방문 배열
    cnt=0
    for i in range(h):
        for j in range(w):
            if board[i][j]==1 and not visited[i][j]: #값이 1이고 방문 안한 칸
                dfs(i,j)
                cnt+=1
    print(cnt)