from collections import deque #앞뒤로 움직이므로 디큐사용
n=int(input())
card=deque()

for i in range(1, n+1):
    card.append(i)
while len(card)>1:
    card.popleft()
    card.append(card.popleft())

print(card[0])