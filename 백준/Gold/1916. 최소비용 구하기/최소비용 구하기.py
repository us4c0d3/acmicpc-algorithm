import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()
INF = 10 ** 9

# main code
n = int(input())
m = int(input())

graph = [[INF] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = min(graph[a][b], c)
s, e = map(int, input().split())

pq = []
cost = [INF] * (n + 1)
heapq.heappush(pq, (0, s))

while pq:
    cur_cost, cur = heapq.heappop(pq)
    if cost[cur] < cur_cost:
        continue
    cost[cur] = cur_cost
    for nxt in range(1, n + 1):
        if graph[cur][nxt] == INF:
            continue
        new_cost = cur_cost + graph[cur][nxt]
        if new_cost < cost[nxt]:
            cost[nxt] = new_cost
            heapq.heappush(pq, (new_cost, nxt))
        

print(cost[e])
