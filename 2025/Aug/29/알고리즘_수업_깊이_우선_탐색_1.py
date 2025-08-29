from sys import stdin as s
import sys
sys.setrecursionlimit(100_001)
input = lambda: s.readline().rstrip()

# main code
def dfs(v, e, r):
    global visited
    global res
    global cnt
    cnt += 1
    visited[r] = True
    res[r - 1] = cnt
    for x in e[r]:
        if not visited[x]:
            dfs(v, e, x)

n, m, r = map(int, input().split())
v = [i for i in range(1, n + 1)]
e = [[] for i in range(n + 1)]
visited = [False] * (n + 1)
res = [0] * n
cnt = 0
for _ in range(m):
    a, b = map(int, input().split())
    e[a].append(b)
    e[b].append(a)

for i in range(1, n + 1):
    e[i].sort()

dfs(v, e, r)
print(*res, sep='\n')
