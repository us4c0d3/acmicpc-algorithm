import sys

input = sys.stdin.readline
result = ""


def isPossible(img, x, y, size):
    t = img[x][y]
    for i in range(x, x + size):
        for j in range(y, y + size):
            if t != img[i][j]:
                return False
    return True


def quadTree(img, x, y, size):
    global result
    if isPossible(img, x, y, size):
        result += str(img[x][y])
        return

    size = size // 2

    result += '('
    quadTree(img, x, y, size)
    quadTree(img, x, y + size, size)
    quadTree(img, x + size, y, size)
    quadTree(img, x + size, y + size, size)
    result += ')'


n = int(input())
img = []
for i in range(n):
    t = list(input().rstrip())
    img.append(t)

quadTree(img, 0, 0, n)
print(result)
