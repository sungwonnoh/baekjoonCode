n,m=map(int, input().split())
arr = []

def dfs(s):
    if len(arr)==m: #배열 길이 m일때
        print(' '.join(map(str,arr)))
        return
    
    for i in range(s, n+1): #시작 숫자부터 입력 후 삭제
        arr.append(i)
        dfs(i)
        arr.pop()

dfs(1)