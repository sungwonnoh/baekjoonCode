from collections import deque

n,m,v=map(int, input().split())
board=[[False]*(n+1) for _ in range(n+1)]
for _ in range(m):
    a,b=map(int, input().split())
    board[a][b]=True
    board[b][a]=True

visited1=[False]*(n+1) #dfs
visited2=[False]*(n+1) #bfs
def dfs(v):
    visited1[v]=True
    print(v, end=" ")
    for i in range(n+1):
        if not visited1[i] and board[v][i]:
            dfs(i)
def bfs(v):
    queue=deque([v]) #시작노드 넣음
    visited2[v]=True
    while queue:
        v=queue.popleft()#처음 값 꺼냄
        print(v, end=" ")
        for i in range(n+1):
            if not visited2[i] and board[v][i]:
                queue.append(i)
                visited2[i]=True

dfs(v)
print()
bfs(v)