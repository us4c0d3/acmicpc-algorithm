from sys import stdin
input = lambda: stdin.readline().rstrip()

# Kruskal
# def find(x):
#     if parent[x] != x:
#         parent[x] = find(parent[x])
#     return parent[x]

# def union(a, b):
#     a = find(a)
#     b = find(b)
#     if a != b:
#         if rank[a] > rank[b]:
#             parent[b] = a
#         elif rank[a] < rank[b]:
#             parent[a] = b
#         else:
#             parent[b] = a
#             rank[a] += 1


n, m = map(int, input().split())
# edges = []
# parent = [i for i in range(n + 1)]
# rank = [0] * (n + 1)
# for _ in range(m):
#     a, b, c = map(int, input().split())
#     edges.append((c, a, b))

# edges.sort()
# res = 0
# max_edge = 0
# for c, a, b in edges:
#     if find(a) != find(b):
#         union(a, b)
#         res += c
#         max_edge = c

# print(res - max_edge)

# Prim
import heapq

pq = []
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

visited = [False] * (n + 1)
heapq.heappush(pq, (0, 1))
max_edge = 0
res = 0
while pq:
    cost, cur = heapq.heappop(pq)
    if visited[cur]:
        continue
    visited[cur] = True
    res += cost
    max_edge = max(max_edge, cost)

    for nxt, nxt_cost in graph[cur]:
        if not visited[nxt]:
            heapq.heappush(pq, (nxt_cost, nxt))

print(res - max_edge)