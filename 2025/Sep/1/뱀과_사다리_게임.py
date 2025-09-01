from sys import stdin as s
from collections import deque
input = lambda: s.readline().rstrip()

# main code
n, m = map(int, input().split())
visited = [0] * 101
graph = [i for i in range(101)]

for i in range(n + m):
    a, b = map(int, input().split())
    graph[a] = b


def bfs():
    q = deque([1])
    visited[1] = 1
    while q:
        cur = q.popleft()

        for dice in range(1, 7):
            next = cur + dice
            if next > 100:
                continue

            t = graph[next]
            if visited[t] == 0:
                q.append(t)
                visited[t] = visited[cur] + 1
                if t == 100:
                    return

bfs()
print(visited[100] - 1)