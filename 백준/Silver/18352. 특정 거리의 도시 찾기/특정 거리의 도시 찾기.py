from collections import deque
import sys
input = sys.stdin.readline

n,m,k,x=map(int, input().split())
board=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int, input().split())
    board[a].append(b)

def bfs(s):
    queue=deque([s])
    visited=[-1]*(n+1)
    visited[s]=0 #시작 도시
    ans=[]

    while queue:
        node = queue.popleft()
        for i in board[node]:
            if visited[i]==-1:
                visited[i]=visited[node]+1
                queue.append(i)

                if visited[i]==k: #k에 도달한 도시
                    ans.append(i)
    check=0 #거리확인
    for i in range(1,n+1):
        if visited[i]==k:
            print(i)
            check+=1
    if check==0:
        print(-1)
bfs(x)