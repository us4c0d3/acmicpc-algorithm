import sys
from collections import deque

input = sys.stdin.readline

dx, dy = [1, 2, 2, 1, -1, -2, -2, -1], [2, 1, -1, -2, -2, -1, 1, 2]

def solve(n, now_x, now_y, dest_x, dest_y):
    matrix = [[0] * n for _ in range(n)]

    q = deque()
    q.append([now_x, now_y])
    matrix[now_x][now_y] = 1

    while q:
        x, y = q.popleft()
        if x == dest_x and y == dest_y:
            return matrix[x][y] - 1

        for i in range(8):
            xx, yy = x + dx[i], y + dy[i]

            if 0 <= xx < n and 0 <= yy < n:
                if matrix[xx][yy] == 0:
                    q.append([xx, yy])
                    matrix[xx][yy] = matrix[x][y] + 1


tc = int(input())
while tc:
    tc -= 1
    n = int(input())
    now_x, now_y = map(int, input().split())
    dest_x, dest_y = map(int, input().split())

    if now_x == dest_x and now_y == dest_y:
        print(0)
        continue

    print(solve(n, now_x, now_y, dest_x, dest_y))
