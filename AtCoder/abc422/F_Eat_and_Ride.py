import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()

# main code
n, m = map(int, input().split())
w = [0] + [*map(int, input().split())]
graph = [[] for _ in range(n + 1)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = {}
pq = []
visited[(1, w[1])] = 0
heapq.heappush(pq, (0, 1, 0)) # cur_cost, node, accum_cost
while pq:
    cur_cost, cur, accum_w = heapq.heappop(pq)

    if cur_cost > visited.get((cur, accum_w), float('inf')):
        continue

    for x in graph[cur]:
        total_cost = cur_cost + accum_w
        new_accum = accum_w + w[x]
        if total_cost < visited.get((x, new_accum), float('inf')):
            visited[(x, new_accum)] = total_cost
            heapq.heappush(pq, (total_cost, x, new_accum))



res = [float('inf')] * (n + 1)
for (x, weight), cost in visited.items():
    res[x] = min(res[x], cost)

for i in range(1, n + 1):
    print(res[i])