import sys
import heapq
sys.setrecursionlimit(10**6)

input = lambda: sys.stdin.readline().rstrip()

# main code
tc = int(input())

def dijkstra(start, n, graph):
    distance = [1000 * 50000 + 1] * (n + 1)
    q = []
    distance[start] = 0
    heapq.heappush(q, (0, start))
    while q:
        dist, cur = heapq.heappop(q)
        if distance[cur] < dist:
            continue
        for nxt, cost in graph[cur]:
            if dist + cost < distance[nxt]:
                distance[nxt] = dist + cost
                heapq.heappush(q, (distance[nxt], nxt))
    return distance


def solve():
    n, m, t = map(int, input().split())
    s, g, h = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b, d = map(int, input().split())
        graph[a].append((b, d))
        graph[b].append((a, d))

    Ds = dijkstra(s, n, graph)
    Dg = dijkstra(g, n, graph)
    Dh = dijkstra(h, n, graph)
    res = []
    for _ in range(t):
        x = int(input())
        if Ds[g] + Dg[h] + Dh[x] == Ds[x] or Ds[h] + Dh[g] + Dg[x] == Ds[x]:
            res.append(x)
    
    res.sort()
    print(*res, sep=' ')
        

for _ in range(tc):
    solve()