n,m=map(int, input().split())
numbers = [int(x) for x in input().split()] #리스트형태로 입력받기

numbers.sort() #오름차순 정렬

arr=[] #정답출력 배열
def dfs(s):
    if len(arr)==m: #배열 길이 m일때
        print(' '.join(map(str,arr)))
        return
    
    for i in range(n): #시작숫자부터 입력 후 삭제
        if numbers[i] not in arr:
            arr.append(numbers[i])
            dfs(s+1) #시작숫자 다음 인덱스
            arr.pop()

dfs(numbers[0])