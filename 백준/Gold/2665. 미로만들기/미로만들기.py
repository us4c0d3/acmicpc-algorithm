import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
INF = 10 ** 9

# main code
n = int(input())
grid = [[1^x for x in [*map(int, input())]] for _ in range(n)]
dq = deque()

dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
dist = [[INF] * n for _ in range(n)]
dq.append((0, 0))
dist[0][0] = 0
while dq:
    cur_x, cur_y = dq.popleft()

    for dx, dy in dirs:
        xx = cur_x + dx
        yy = cur_y + dy
        
        if not (0 <= xx < n and 0 <= yy < n):
            continue
        
        if grid[xx][yy] and dist[xx][yy] > dist[cur_x][cur_y] + 1:
            dist[xx][yy] = dist[cur_x][cur_y] + 1
            dq.append((xx, yy))
        elif grid[xx][yy] == 0 and dist[xx][yy] > dist[cur_x][cur_y]:
            dist[xx][yy] = dist[cur_x][cur_y]
            dq.appendleft((xx, yy))
    
print(dist[n - 1][n - 1])
