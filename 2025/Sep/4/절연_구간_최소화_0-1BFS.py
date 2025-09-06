from sys import stdin as s
from collections import deque
input = lambda: s.readline().rstrip()

# main code
n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for i in range(m):
    start, end, t = map(int, input().split())
    graph[start].append([end, t])
    graph[end].append([start, t])
a, b = map(int, input().split())

dist = [[float('inf')] * 2 for _ in range(n + 1)]
dist[a][0] = dist[a][1] = 0
dq = deque()
dq.append([a, -1])

while dq:
    cur, cur_t = dq.popleft()

    for next_x, next_t in graph[cur]:
        if cur_t == -1:
            dist[next_x][next_t] = 0
            dq.appendleft([next_x, next_t])
        else:
            if dist[next_x][next_t] > dist[cur][cur_t] + (cur_t ^ next_t):
                dist[next_x][next_t] = dist[cur][cur_t] + (cur_t ^ next_t)
                if cur_t ^ next_t == 0:
                    dq.appendleft([next_x, next_t])
                else:
                    dq.append([next_x, next_t])

print(min(dist[b]))
