from sys import stdin as s
from collections import deque
input = lambda: s.readline().rstrip()

# main code
n, m = map(int, input().split())

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
grid = []
visited = [[[0, 0] for i in range(m)] for j in range(n)]
visited[0][0][0] = 1


for i in range(n):
    tmp = [*map(int, input())]
    grid.append(tmp)


def bfs():
    q = deque()
    q.append([0, 0, 0])

    while q:
        x, y, broken = q.popleft()
        
        if x == n - 1 and y == m - 1:
            return visited[x][y][broken]
        
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if not (0 <= nx <= n - 1 and 0 <= ny <= m - 1):
                continue

            if grid[nx][ny] == 1 and broken == 0:
                visited[nx][ny][1] = visited[x][y][0] + 1
                q.append([nx, ny, 1])
            
            elif grid[nx][ny] == 0 and visited[nx][ny][broken] == 0:
                visited[nx][ny][broken] = visited[x][y][broken] + 1
                q.append([nx, ny, broken])
    
    return -1

print(bfs())