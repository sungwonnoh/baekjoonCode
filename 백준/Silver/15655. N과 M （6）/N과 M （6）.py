n,m=map(int, input().split())
numbers = [int(x) for x in input().split()]

numbers.sort()
arr=[] #정답출력배열

def dfs(s):
    if len(arr)==m:
        print(' '.join(map(str,arr)))
        return

    for i in range(s,n):
        if numbers[i] not in arr: #중복제거
            arr.append(numbers[i])
            dfs(i+1) #다음 인덱스 숫자
            arr.pop()
dfs(0)