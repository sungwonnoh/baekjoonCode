from collections import deque

n,k=map(int, input().split())
max_num=100000 #최대값
visited=[0]*(max_num+1)

def bfs(v):
    queue=deque([v]) 
    visited[v]=0 #시작위치
    while queue:
        cur=queue.popleft()
        if cur==k:
            print(visited[cur]) 
            break
        for i in (cur-1, cur+1, cur*2): #이동방향
            if 0<=i <=max_num and visited[i]==0:
                visited[i]=visited[cur]+1
                queue.append(i)
bfs(n)