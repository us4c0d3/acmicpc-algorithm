from sys import stdin as s
import heapq
input = lambda: s.readline().rstrip()

# main code
n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for i in range(m):
    start, end, t = map(int, input().split())
    graph[start].append([end, t])
    graph[end].append([start, t])
a, b = map(int, input().split())

dist = [float('inf')] * (n + 1)

dist[a] = 0
q = []
heapq.heappush(q, [dist[a], a, -1])

while q:
    cur_dist, cur, cur_t = heapq.heappop(q)

    for next_x, next_t in graph[cur]:
        if cur_t == -1:
            dist[next_x] = dist[cur]
            heapq.heappush(q, [dist[next_x], next_x, next_t])
        
        elif dist[next_x] > dist[cur] + (cur_t ^ next_t):
            dist[next_x] = dist[cur] + (cur_t ^ next_t)
            heapq.heappush(q, [dist[next_x], next_x, next_t])

print(dist[b])