import sys
import heapq
input = sys.stdin.readline

n,m=map(int, input().split())
card=list(map(int, input().split()))
heapq.heapify(card) #최소 힙으로 정렬

for i in range(m):
    c1=heapq.heappop(card) #가장 작은 카드 꺼냄
    c2=heapq.heappop(card)
    heapq.heappush(card, c1+c2)
    heapq.heappush(card, c1+c2)
print(sum(card))