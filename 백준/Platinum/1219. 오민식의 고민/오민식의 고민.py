import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
INF = 10 ** 9

# main code
n, s, e, m = map(int, input().split())
edges = [[*map(int, input().split())] for _ in range(m)]
rev_graph = [[] for _ in range(n)]

# 정점 가중치를 간선으로 이동
costs = [*map(int, input().split())]
for i in range(m):
    edges[i][2] = costs[edges[i][1]] - edges[i][2]
    
# 역방향 그래프
for edge in edges:
    rev_graph[edge[1]].append(edge[0])

can_reach = [False] * n

q = deque([e])
while q:
    cur = q.popleft()
    can_reach[cur] = True
    for prev in rev_graph[cur]:
        if not can_reach[prev]:
            q.append(prev)

dist = [-INF] * n
dist[s] = costs[s]  # 시작 가중치는 정점 가중치

for _ in range(n - 1):
    updated = False
    for a, b, c in edges:
        if dist[a] != -INF and dist[a] + c > dist[b]:
            updated = True
            dist[b] = dist[a] + c
    if not updated:
        break

if dist[e] == -INF:
    print('gg')
    sys.exit()

for a, b, c in edges:
    if dist[a] != -INF and dist[a] + c > dist[b] and can_reach[b]:
        print('Gee')
        sys.exit()

print(dist[e])

### 틀린 사유
# 이 문제에서 Gee가 출력되는 조건은 양의 사이클을 통과하는 채로 e에 도달할 때만.
# 아니라면 Gee가 아님
# 현재 코드는 그래프에 양의 사이클이 존재하면 무조건 Gee를 출력하도록 되어있음
# 해결 방법: rev_graph로 e에서 시작하여 bfs를 통해 도달가능한지 체크