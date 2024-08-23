n,d=map(int, input().split())
arr=[]
dp=[i for i in range(d+1)]   
for _ in range(n):
    start, end, path=list(map(int, input().split()))
    if end - start > path:
        arr.append((start,end,path))
arr.sort() #오름차순 정렬

for start, end, path in arr:
    for i in range(1, d+1):
        if end==i:
            dp[i]=min(dp[i], dp[start]+path) #지름길과 일반길 중 최소값 선택
        else:
            dp[i]=min(dp[i], dp[i-1]+1)
print(dp[d])