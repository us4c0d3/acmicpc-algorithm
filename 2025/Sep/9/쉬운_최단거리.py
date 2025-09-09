import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

# main code
n, m = map(int, input().split())
grid = [[] for _ in range(n)]
visited = [[-1] * m for _ in range(n)]
start = (-1, -1)


for i in range(n):
    tmp = [*map(int, input().split())]
    grid[i] = tmp

for i in range(n):
    for j in range(m):
        if grid[i][j] == 2:
            start = (i, j)
            visited[i][j] = 0
        elif grid[i][j] == 0:
            visited[i][j] = 0

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

q = deque([start])
while q:
    x, y = q.popleft()
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        
        if not (0 <= nx < n and 0 <= ny < m):
            continue
        
        if visited[nx][ny] == -1 and grid[nx][ny] == 1:
            visited[nx][ny] = visited[x][y] + 1
            q.append((nx, ny))
    
for i in range(n):
    print(*visited[i], sep=' ')