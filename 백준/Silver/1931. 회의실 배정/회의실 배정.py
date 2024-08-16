n=int(input())
arr=[[0,0]]
for i in range(n):
    s,e=list(map(int, input().split()))
    arr.append((s,e))

arr.sort(key=lambda x:(x[1],x[0])) #오름차순 정렬
cnt=0
end=0 
for i in range(1,n+1):
    if arr[i][0] >= end:
        cnt+=1
        end = arr[i][1]#마지막 종료시간 저장
print(cnt)