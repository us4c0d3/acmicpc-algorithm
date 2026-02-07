import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
h, w, j = map(int, input().split())
grid = [[] for _ in range(h)]
for i in range(h):
    tmp = [*map(int, input().split())]
    grid[i] = tmp

res = 0 
s = set()
for i in range(j):
    tmp = int(input())
    s.add(tmp)

for i in range(h):
    cnt = 0
    for x in grid[i]:
        if x in s:
            cnt += 1
    if cnt > res:
        res = cnt

print(res)