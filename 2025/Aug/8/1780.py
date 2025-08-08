import sys
input = sys.stdin.readline

result = [0, 0, 0]


def isPossible(paper, x, y, size):
    t = paper[x][y]
    for i in range(x, x + size):
        for j in range(y, y + size):
            if t != paper[i][j]:
                return False
    return True


def solve(paper, x, y, size):
    if isPossible(paper, x, y, size):
        result[paper[x][y]] += 1
        return

    size = size // 3
    solve(paper, x, y, size)
    solve(paper, x, y + size, size)
    solve(paper, x, y + size + size, size)
    solve(paper, x + size, y, size)
    solve(paper, x + size, y + size, size)
    solve(paper, x + size, y + size + size, size)
    solve(paper, x + size + size, y, size)
    solve(paper, x + size + size, y + size, size)
    solve(paper, x + size + size, y + size + size, size)


n = int(input())
paper = []
for i in range(n):
    t = list(map(int, input().rstrip().split()))
    paper.append(t)

solve(paper, 0, 0, n)
for i in range(-1, 2):
    print(result[i])
