n,m = map(int, input().split())
numbers=[int(x) for x in input().split()]
numbers.sort()
arr=[]

def dfs(s):
    if len(arr)==m:
        print(' '.join(map(str,arr)))
        return
    for i in range(s,n):
        arr.append(numbers[i])
        dfs(i) #numbers 리스트는 이미 정렬됨
        arr.pop()
dfs(0)