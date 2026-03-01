import sys

input = lambda: sys.stdin.readline().rstrip()
INF = 10 ** 9

# main code
n, m = map(int, input().split())

reach = [[False] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    h, l = map(int, input().split())
    reach[h][l] = 1


for i in range(n + 1):
    reach[i][i] = True
    
for k in range(1, n + 1):
    for i in range(1, n + 1):
        if not reach[i][k]:
            continue
        for j in range(1, n + 1):
            if reach[k][j]:
                reach[i][j] = True

half = n // 2
res = 0
for i in range(1, n + 1):
    light = 0
    heavy = 0
    for j in range(1, n + 1):
        if i == j:
            continue
        if reach[i][j]:
            light += 1
        if reach[j][i]:
            heavy += 1
    if light > half or heavy > half:
        res += 1
        
print(res)
