import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
h, w = map(int, input().split())
grid = []
for i in range(h):
    tmp = list(input())
    grid.append(tmp)

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def solve():
    for i in range(h):
        for j in range(w):
            if grid[i][j] == '#':
                cnt = 0
                for x in range(4):
                    ni, nj = i + dy[x], j + dx[x]
                    if not (0 <= ni < h and 0 <= nj < w):
                        continue
                    if grid[ni][nj] == '#':
                        cnt += 1
                if cnt != 2 and cnt != 4:
                    print('No')
                    return
    
    print('Yes')

solve()