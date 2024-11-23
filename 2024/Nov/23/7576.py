import sys
from collections import deque

input = sys.stdin.readline

m, n = map(int, input().split())
box = [list(map(int, input().rstrip().split())) for _ in range(n)]
q = deque([])
dx, dy = [0, 0, 1, -1], [-1, 1, 0, 0]

for i in range(n):
    for j in range(m):
        if box[i][j] == 1:
            q.append([i, j])

while q:
    x, y = q.popleft()
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < n and 0 <= ny < m and box[nx][ny] == 0:
            box[nx][ny] = box[x][y] + 1
            q.append((nx, ny))

if any(0 in row for row in box):
    print(-1)
else:
    print(max(max(row) for row in box) - 1)
