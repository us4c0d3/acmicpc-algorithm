import sys
from collections import deque

input = sys.stdin.readline

m, n, h = map(int, input().split())
box = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
visited = [[[False] * m for _ in range(n)] for _ in range(h)]
q = deque()
dx, dy, dz = [-1, 1, 0, 0, 0, 0], [0, 0, -1, 1, 0, 0], [0, 0, 0, 0, -1, 1]

for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 1 and visited[i][j][k] is False:
                q.append([i, j, k])
                visited[i][j][k] = True

while q:
    x, y, z = q.popleft()
    for i in range(6):
        nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]

        if nx < 0 or nx >= h or ny < 0 or ny >= n or nz < 0 or nz >= m:
            continue

        if box[nx][ny][nz] == 0 and visited[nx][ny][nz] is False:
            box[nx][ny][nz] = box[x][y][z] + 1
            q.append([nx, ny, nz])
            visited[nx][ny][nz] = True

res = -1

for i in box:
    for j in i:
        for k in j:
            if k == 0:
                print(-1)
                exit(0)

        res = max(res, max(j))

print(res - 1)
