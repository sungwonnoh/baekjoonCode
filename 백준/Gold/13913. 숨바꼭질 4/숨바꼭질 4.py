from collections import deque

n, k = map(int, input().split())
max_num = 100000
visited = [0] * (max_num + 1)
parent=[-1]*(max_num+1) #이동경로
def bfs(v):
    q = deque([v]) 
    visited[v] = 1  # 시작 위치 방문 표시
    while q:
        cur = q.popleft()
        if cur == k:
            print(visited[cur]-1)
            path=[]
            while cur!=-1:
                path.append(cur)
                cur=parent[cur]
            print(" ".join(map(str, path[::-1]))) #역순으로 출력
            return
        for i in (cur - 1, cur + 1, cur * 2):
            if 0 <= i <= max_num and visited[i] == 0:
                visited[i] = visited[cur] + 1
                parent[i]=cur
                q.append(i)
bfs(n)