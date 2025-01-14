import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
g = [[] for _ in range(n + 1)]
indegree = [0 for _ in range(n + 1)]

for i in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
    indegree[b] += 1

q = deque()

for i in range(1, n + 1):
    if indegree[i] == 0:
        q.append(i)

while q:
    cur = q.popleft()
    print(cur, end=' ')
    for i in range(len(g[cur])):
        next = g[cur][i]
        indegree[next] -= 1
        if indegree[next] == 0:
            q.append(next)
