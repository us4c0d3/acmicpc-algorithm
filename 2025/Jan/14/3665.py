import sys
from collections import deque

input = sys.stdin.readline

def topological_sort(n, graph, inDegree, isLinked):
    queue = deque()
    res = []
    for team in range(1, n + 1):
        if inDegree[team] == 0:
            queue.append(team)

    while queue:
        team = queue.popleft()
        res.append(team)

        for neighbor in graph[team]:
            if isLinked[team][neighbor] == 0:
                continue
            inDegree[neighbor] -= 1
            if inDegree[neighbor] == 0:
                queue.append(neighbor)

    return res


tc = int(input())
while tc:
    tc -= 1

    # 팀 수
    n = int(input())

    g = [[] for _ in range(n + 1)]
    inDegree = [0 for _ in range(n + 1)]
    isLinked = [[0] * (n + 1) for _ in range(n + 1)]

    # 작년 순위
    arr_t = list(map(int, input().split()))
    for i in range(n - 1):
        for j in range(i + 1, n):
            t1 = arr_t[i]
            t2 = arr_t[j]

            g[t1].append(t2)
            isLinked[t1][t2] = True
            inDegree[t2] += 1

    m = int(input())
    for i in range(m):
        a, b = map(int, input().split())
        if isLinked[a][b]:
            g[b].append(a)
            isLinked[a][b] = False
            isLinked[b][a] = True
            inDegree[b] -= 1
            inDegree[a] += 1
        elif isLinked[b][a]:
            g[a].append(b)
            isLinked[b][a] = False
            isLinked[a][b] = True
            inDegree[a] -= 1
            inDegree[b] += 1

    res = topological_sort(n, g, inDegree, isLinked)

    if len(res) < n:
        print("IMPOSSIBLE")
    else:
        print(*res, sep=' ')
