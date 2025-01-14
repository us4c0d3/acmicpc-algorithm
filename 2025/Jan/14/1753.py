import sys
import heapq

input = sys.stdin.readline

INF = float('inf')

v, e = map(int, input().split())
k = int(input())

g = [[] for _ in range(v + 1)]
distance = [INF for _ in range(v + 1)]
q = []

for i in range(e):
    u, v, w = map(int, input().split())
    g[u].append((v, w))

heapq.heappush(q, (0, k))
distance[k] = 0

while q:
    dist, cur = heapq.heappop(q)

    if distance[cur] < dist:
        continue

    for i in g[cur]:
        if dist + i[1] < distance[i[0]]:
            distance[i[0]] = dist + i[1]
            heapq.heappush(q, (dist + i[1], i[0]))

for i in range(1, len(distance)):
    if distance[i] == INF:
        print('INF')
    else:
        print(distance[i])
