n,m=map(int, input().split())
numbers=[int(x) for x in input().split()]
numbers.sort()
arr=[]

def dfs():
    if len(arr)==m:
        print(' '.join(map(str,arr)))
        return
    for i in range(n):
        arr.append(numbers[i])
        dfs()
        arr.pop()
dfs()