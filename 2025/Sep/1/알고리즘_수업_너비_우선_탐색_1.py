from sys import stdin as s
from collections import deque
input = lambda: s.readline().rstrip()

# main code
n, m, r = map(int, input().split())

v = [i for i in range(1, n + 1)]
e = [[] for i in range(n + 1)]
q = deque([])
visited = [False] * (n + 1)
res = [0] * n
cnt = 1


for i in range(m):
    a, b = map(int, input().split())
    e[a].append(b)
    e[b].append(a)

for i in range(1, n + 1):
    e[i].sort()


q.append(r)
visited[r] = True
res[r - 1] = cnt

while q:
    a = q.popleft()
    for x in e[a]:
        if not visited[x]:
            cnt += 1
            res[x - 1] = cnt
            visited[x] = True
            q.append(x)

print(*res, sep='\n')