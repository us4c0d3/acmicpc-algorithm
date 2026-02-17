from sys import stdin
import heapq
input = lambda: stdin.readline().rstrip()

# main code
n = int(input())
maxheap = []
minheap = []
for i in range(n):
    cur = int(input())
    if i & 1:
        heapq.heappush(minheap, cur)
    else:
        heapq.heappush(maxheap, -cur)
    
    if maxheap and minheap:
        if minheap[0] < -maxheap[0]:
            a, b = heapq.heappop(minheap), -heapq.heappop(maxheap)
            heapq.heappush(maxheap, -a)
            heapq.heappush(minheap, b)

    print(-maxheap[0])
