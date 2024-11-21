import sys

input = sys.stdin.readline

n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]
w = 0
b = 0

def recur(y, x, N):
    global w, b
    color = paper[y][x]
    for i in range(y, y+N):
        for j in range(x, x+N):
            if color != paper[i][j]:
                size = N // 2
                recur(y, x, size)
                recur(y, x + N // 2, size)
                recur(y + N // 2, x, size)
                recur(y + N // 2, x + N // 2, size)
                return
    if color == 0:
        w += 1
    else:
        b += 1


recur(0, 0, n)
print(w, b, sep='\n')
