from sys import stdin
input = lambda: stdin.readline().rstrip()

INF = 10 ** 9

def move_left(line):
    cur = [line[i] for i in range(n) if line[i] != 0]
    idx = 0
    while idx < len(cur) - 1:
        if cur[idx] == cur[idx + 1]:
            cur[idx] *= 2
            cur.pop(idx + 1)
        idx += 1
    return cur + [0] * (n - len(cur))


n = int(input())
board = [[*map(int, input().split())] for _ in range(n)]

res = -INF

def dfs(cnt, board):
    global res
    if cnt == 5:
        tmp = 0
        for i in range(n):
            tmp = max(tmp, max(board[i]))
        if tmp > res:
            res = tmp
        return        

    cur_board = [row[:] for row in board]
    nxt_board = [[] for _ in range(n)]
    for _ in range(4):
        for i in range(n):
            nxt_board[i] = move_left(cur_board[i])
        dfs(cnt + 1, nxt_board)
        cur_board = [list(row) for row in zip(*cur_board[::-1])]


dfs(0, board)
print(res)
