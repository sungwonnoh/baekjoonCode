from collections import deque

n, l, r = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(a, b):
    q = deque()
    union = []
    q.append((a, b))
    union.append((a, b))
    visited[a][b] = 1

    while q:
        x, y = q.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < n and 0 <= ny < n and visited[nx][ny] == 0:
                if l <= abs(graph[nx][ny] - graph[x][y]) <= r:
                    visited[nx][ny] = 1
                    q.append((nx, ny))
                    union.append((nx, ny))
    return union

result = 0
while True:
    visited = [[0 for _ in range(n)] for _ in range(n)]
    flag = 0
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0:
                country = bfs(i, j)

                if len(country) > 1:  # 2개 이상 이동 시
                    flag = 1
                    total = sum(graph[x][y] for x, y in country)
                    people = total // len(country)
                    
                    for x, y in country:
                        graph[x][y] = people

    if flag == 0:  # 인구 이동 종료 시
        print(result)
        break

    result += 1