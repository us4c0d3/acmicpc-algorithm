from sys import stdin
input = lambda: stdin.readline().rstrip()

import heapq

# main code
n = int(input())
cards = []

for _ in range(n):
    heapq.heappush(cards, int(input()))

res = 0

for _ in range(n - 1):
    a = heapq.heappop(cards)
    b = heapq.heappop(cards)
    res += a + b
    heapq.heappush(cards, a + b)

print(res)
