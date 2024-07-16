n,m=map(int, input().split())
arr=[]

def dfs():
    if len(arr)==m: #배열 길이 m일때
        print(' '.join(map(str,arr)))
        return
    
    for i in range(1, n+1): #1부터 입력 후 삭제
        arr.append(i)
        dfs()
        arr.pop()

dfs()