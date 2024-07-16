n,m=map(int, input().split())
arr=[]

def dfs(s):
    if len(arr)==m: #배열 길이 m일때
        print(' '.join(map(str,arr)))
        return
    
    for i in range(s, n+1): #시작숫자부터 입력 후 삭제
        if i not in arr: #같은 숫자 중복 X
            arr.append(i)
            dfs(1)
            arr.pop()

dfs(1)