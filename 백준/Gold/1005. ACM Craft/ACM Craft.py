import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

# main code
t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    costs = [0] + [*map(int, input().split())]    
    indegree = [0] * (n + 1)
    graph = [[] for _ in range(n + 1)]
    for _ in range(k):
        a, b = map(int, input().split())
        graph[a].append(b)
        indegree[b] += 1
    w = int(input())

    q = deque()
    res = [0] * (n + 1)
    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)
            res[i] = costs[i]
    
    while q:
        cur = q.popleft()
        for nxt in graph[cur]:
            indegree[nxt] -= 1
            if indegree[nxt] == 0:
                q.append(nxt)
            res[nxt] = max(res[nxt], res[cur] + costs[nxt])
    
    print(res[w])
