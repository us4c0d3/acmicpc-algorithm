from sys import stdin
from collections import deque
input = lambda: stdin.readline().rstrip()

# main code
n = int(input())
m = int(input())
visited = [False] * (n + 1)
grid = [[] for _ in range(n)]
for i in range(n):
    tmp = [*map(int, input().split())]
    grid[i] = tmp
plan = [*map(int, input().split())]

def bfs(s):
    q = deque()
    q.append(s)
    visited[s] = True
    while q:
        cur = q.pop()
        for i in range(n):
            if grid[cur][i] and not visited[i]:
                visited[i] = True
                q.append(i)

def solve():
    bfs(plan[0] - 1)
    for p in plan:
        if not visited[p - 1]:
            print('NO')
            return
    print('YES')

solve()