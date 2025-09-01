from sys import stdin as s
import sys
sys.setrecursionlimit(100001)
input = lambda: s.readline().rstrip()


# main code
n, m, r = map(int, input().split())

v = [i for i in range(1, n + 1)]
e = [[] for i in range(n + 1)]
visited = [False] * (n + 1)
cnt = 0
res = [0] * n

for i in range(m):
    a, b = map(int, input().split())
    e[a].append(b)
    e[b].append(a)

for i in range(1, n + 1):
    e[i].sort(reverse=True)

def dfs(v, e, r):
    global cnt
    visited[r] = True
    cnt += 1
    res[r - 1] = cnt
    for x in e[r]:
        if not visited[x]:
            dfs(v, e, x)

dfs(v, e, r)
print(*res, sep='\n')