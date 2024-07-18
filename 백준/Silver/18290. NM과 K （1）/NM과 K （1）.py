import sys
input = sys.stdin.readline

n,m,k=map(int, input().split())
board=[list(map(int, input().split())) for _ in range(n)]
dy=[0,1,0,-1] #행 이동
dx=[1,0,-1,0] #열 이동

maxSum = float('-inf') #음의 무한대 표시(최대값구할때 자주사용)
selected = [[False]*m for _ in range(n)] #nxm 2차원배열, 초기 false로 설정

def flag(r,c): #선택가능한 칸인지 확인하는 함수
    for i in range(4):
        nr,nc=r+dy[i], c+dx[i]
        if 0 <= nr < n and 0 <= nc < m and selected[nr][nc]:#인접한 칸일경우
            return False
    return True

def dfs(cnt, curSum, sr,sc):
    global maxSum #전역변수
    if cnt == k: #k만큼 골랐다면
        maxSum = max(maxSum, curSum) #최대값찾기
        return
    if cnt + (n*m- sr*m-sc)<k:
        return
    for r in range(sr, n):
        for c in range(sc if r==sr else 0, m):
            if not selected[r][c] and flag(r,c): #현재 칸이 선택되지 않았을때
                selected[r][c]= True
                dfs(cnt+1, curSum + board[r][c],r,c) #cnt값과 합을 갱신
                selected[r][c]=False

dfs(0,0,0,0)
print(maxSum)