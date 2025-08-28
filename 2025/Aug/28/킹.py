from sys import stdin as s
input = lambda: s.readline().rstrip()

# main code
king, stone, n = input().split()
n = int(n)

dx = (1, -1, 0, 0, 1, -1, 1, -1)
dy = (0, 0, -1, 1, 1, 1, -1, -1)
direction = {'R': 0, 'L': 1, 'B': 2, 'T': 3, 'RT': 4, 'LT': 5, 'RB': 6, 'LB': 7}


def codeToNum(code):
    x = ord(code[0]) - ord('A')
    y = int(code[1]) - 1
    return [x, y]


def numToCode(num):
    x = chr(num[0] + ord('A'))
    return f'{x}{num[1] + 1}'


cur_k = codeToNum(king)
cur_s = codeToNum(stone)

for i in range(n):
    move = input()
    nx = cur_k[0] + dx[direction[move]]
    ny = cur_k[1] + dy[direction[move]]

    if not (0 <= nx <= 7 and 0 <= ny <= 7):
        continue
    
    if [nx, ny] == cur_s:
        mx = cur_s[0] + dx[direction[move]]
        my = cur_s[1] + dy[direction[move]]
        if not (0 <= mx <= 7 and 0 <= my <= 7):
            continue      
        cur_s = [mx, my]

    cur_k = [nx, ny]

print(numToCode(cur_k))
print(numToCode(cur_s))