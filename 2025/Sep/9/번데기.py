import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
a = int(input())
t = int(input())
x = int(input())

game = []
bbun = degi = 1
n = 0

while True:
    prev_n = bbun
    n += 1
    for _ in range(2):
        game.append((bbun, 0))
        game.append((degi, 1))
        bbun += 1
        degi += 1

    for _ in range(n + 1):
        game.append((bbun, 0))
        bbun += 1
    
    for _ in range(n + 1):
        game.append((degi, 1))
        degi += 1
    
    if prev_n < t <= bbun:
        print(game.index((t, x)) % a)
        break 