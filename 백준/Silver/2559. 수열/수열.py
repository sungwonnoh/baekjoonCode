n,k=map(int, input().split())
t=list(map(int, input().split()))

Sum=[0]*(n+1) #합 배열 초기화
for i in range(1,n+1):
    Sum[i]=t[i-1]+Sum[i-1]

ans = Sum[k]
for j in range(k, n+1):
    ans = max(ans, Sum[j]-Sum[j-k]) #최대값 찾기
print(ans)