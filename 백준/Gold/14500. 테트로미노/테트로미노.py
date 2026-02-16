from sys import stdin
input = lambda: stdin.readline().rstrip()

# main code
I = [
    [(0, 0), (0, 1), (0, 2), (0, 3)],
    [(0, 0), (1, 0), (2, 0), (3, 0)]
]

O = [
    [(0, 0), (0, 1), (1, 0), (1, 1)]
]

L = [
    [(0, 0), (1, 0), (2, 0), (2, 1)],
    [(0, 0), (1, 0), (0, 1), (0, 2)],
    [(0, 0), (0, 1), (1, 1), (2, 1)],
    [(0, 2), (1, 0), (1, 1), (1, 2)]
]

J = [
    [(2, 0), (0, 1), (1, 1), (2, 1)],
    [(0, 0), (1, 0), (1, 1), (1, 2)],
    [(0, 0), (1, 0), (2, 0), (0, 1)],
    [(0, 0), (0, 1), (0, 2), (1, 2)]
]

S = [
    [(0, 0), (1, 0), (1, 1), (2, 1)],
    [(1, 0), (1, 1), (0, 1), (0, 2)]
]

Z = [
    [(0, 1), (1, 0), (1, 1), (2, 0)],
    [(0, 0), (0, 1), (1, 1), (1, 2)]
]

T = [
    [(0, 0),(0, 1),(0, 2),(1, 1)],  # T
    [(0, 1),(1, 0),(1, 1),(2, 1)],  # ㅓ
    [(0, 1),(1, 0),(1, 1),(1, 2)],  # ㅗ
    [(0, 0),(1, 0),(2, 0),(1, 1)]   # ㅏ
]

shapes = [*I, *O, *L, *J, *S, *Z, *T]

n, m = map(int, input().split())
grid = [[*map(int, input().split())] for _ in range(n)]

# 500 * 500 * 19 * 4 = 19,000,000
res = -1
for i in range(n):
    for j in range(m):
        for shape in shapes:
            tmp = 0
            flag = False
            for dx, dy in shape:
                xx = i + dx
                yy = j + dy
                if not (0 <= xx < n and 0 <= yy < m):
                    flag = True
                    break
                
                tmp += grid[xx][yy]

            if flag:
                continue

            if tmp > res:
                res = tmp

print(res)