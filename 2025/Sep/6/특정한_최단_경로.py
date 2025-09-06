import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()

# main code
def solve():
    n, e = map(int, input().split())
    graph = [[] for _ in range(n + 1)]

    for i in range(e):
        a, b, c = map(int, input().split())
        graph[a].append((b, c))
        graph[b].append((a, c))
    a, b = map(int, input().split())


    def dijkstra(s, graph):
        dist = [float('inf')] * (n + 1)
        dist[s] = 0
        pq = []
        heapq.heappush(pq, (dist[s], s))

        while pq:
            cur_dist, cur = heapq.heappop(pq)

            for nxt, cost in graph[cur]:
                if dist[nxt] > cur_dist + cost:
                    dist[nxt] = cur_dist + cost
                    heapq.heappush(pq, (dist[nxt], nxt))
        
        return dist

    dist1 = dijkstra(1, graph)
    dista = dijkstra(a, graph)
    distb = dijkstra(b, graph)
    
    path1 = dist1[a] + dista[b] + distb[n]
    path2 = dist1[b] + distb[a] + dista[n]

    res = min(path1, path2)
    print(res if res < float('inf') else -1)

if __name__ == '__main__':
    solve()