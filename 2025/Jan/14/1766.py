import sys
import heapq

input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
inDegree = [0 for _ in range(n + 1)]
queue = []

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    inDegree[b] += 1

for i in range(1, n + 1):
    if inDegree[i] == 0:
        heapq.heappush(queue, i)

res = []

while queue:
    cur = heapq.heappop(queue)
    res.append(cur)
    for i in graph[cur]:
        inDegree[i] -= 1
        if inDegree[i] == 0:
            heapq.heappush(queue, i)

print(*res, sep=' ')
