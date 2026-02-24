import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n, m, x, y, k = map(int, input().split())
grid = [[*map(int, input().split())] for _ in range(n)]
commands = [*map(int, input().split())]

dirs = [None, (0, 1), (0, -1), (-1, 0), (1, 0)]

# T B N S E W
# 1: E W N S B T
# 2: W E N S T B
# 3: N S B T E W
# 4: S N T B E W
dice = [0, 0, 0, 0, 0, 0]
for cmd in commands:
    xx = x + dirs[cmd][0]
    yy = y + dirs[cmd][1]
    if not (0 <= xx < n and 0 <= yy < m):
        continue
    x, y = xx, yy
    T, B, N, S, E, W = dice
    if cmd == 1:
        dice = [E, W, N, S, B, T]
    elif cmd == 2:
        dice = [W, E, N, S, T, B]
    elif cmd == 3:
        dice = [N, S, B, T, E, W]
    elif cmd == 4:
        dice = [S, N, T, B, E, W]
    
    if grid[x][y] == 0:
        grid[x][y] = dice[1]
    else:
        dice[1] = grid[x][y]
        grid[x][y] = 0

    print(dice[0])
