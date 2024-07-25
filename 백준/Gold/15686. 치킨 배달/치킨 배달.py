n,m=map(int, input().split())
home=[]
chicken=[]
for i in range(n):
    board=list(map(int, input().split()))
    for j in range(n):
        if board[j]==1:
            home.append((i,j))
        elif board[j]==2:
            chicken.append((i,j))

visited = [False] * len(chicken)
min_ans = float('inf')
def dfs(a,b):
    global min_ans
    if b==m:
        ans=0
        for i in home:
            distance = float("inf") #초기 거리 최대값
            for j in range(len(chicken)):
                if visited[j]:
                    location = abs(i[0]-chicken[j][0])+ abs(i[1]-chicken[j][1]) #거리 공식
                    distance = min(distance, location) #최소거리
            ans += distance #치킨거리의 합
        min_ans = min(ans, min_ans)
        return
        
    for i in range(a, len(chicken)): #치킨집 탐색
        if not visited[i]:
            visited[i]=True
            dfs(i+1, b+1)
            visited[i]=False
dfs(0,0)
print(min_ans)