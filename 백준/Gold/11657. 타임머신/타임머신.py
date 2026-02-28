import sys

input = lambda: sys.stdin.readline().rstrip()
INF = 10 ** 9

# main code
n, m = map(int, input().split())
edges = []
for _ in range(m):
    edges.append([*map(int, input().split())])

dist = [INF] * (n + 1)
dist[1] = 0
for _ in range(n - 1):
    for a, b, c in edges:
        if dist[a] != INF and dist[a] + c < dist[b]:
            dist[b] = dist[a] + c

neg = False
for a, b, c in edges:
    if dist[a] != INF and dist[a] + c < dist[b]:
        neg = True
        
if neg:
    print(-1)
else:
    for i in range(2, n + 1):
        print(dist[i] if dist[i] != INF else -1)