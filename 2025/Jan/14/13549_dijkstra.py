import sys
import heapq

input = sys.stdin.readline
MAX_SIZE = 100001
INF = float('inf')

n, k = map(int, input().split())
distance = [INF] * MAX_SIZE
queue = []

distance[n] = 0
heapq.heappush(queue, (0, n))

while queue:
    dist, cur = heapq.heappop(queue)

    if distance[cur] < dist:
        continue

    for i in (cur + 1, cur - 1, cur * 2):
        if i < 0 or i >= MAX_SIZE:
            continue

        tmp = dist
        if i != cur * 2:
            tmp = dist + 1

        if tmp < distance[i]:
            distance[i] = tmp
            heapq.heappush(queue, (tmp, i))

print(distance[k])
