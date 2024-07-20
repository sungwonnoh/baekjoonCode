import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n,m,r=map(int, input().split())
arr=[[]for _ in range(n+1)] #2차원 배열, 인덱스 0은 무시
visited=[0]*(n+1) #방문배열
ans=[0]*(n+1) #정답
cnt=1 #횟수

for _ in range(m):
    u,v=map(int, input().split())
    arr[u].append(v) #양방향이므로 서로 넣어줌
    arr[v].append(u)

for i in range(1, n + 1):
    arr[i].sort(reverse=True)#내림차순 정렬

def dfs(s):
    global cnt
    visited[s]=True
    ans[s]=cnt
    for i in arr[s]:
        if not visited[i]:
            cnt+=1
            dfs(i)
dfs(r)

for j in ans[1:]: #인덱스 1부터 출력
    print(j)