m, n = map(int, input().split())
if m > n: #세로가 길때
    print(n*2-1)
else: #가로가 길때
    print(m*2-2)