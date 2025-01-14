import sys
from collections import deque

input = sys.stdin.readline
MAX_SIZE = 100001

n, k = map(int, input().split())
dist = [0] * MAX_SIZE
queue = deque()

dist[n] = 0
queue.append(n)

res = 0
cnt = 0

while queue:
    cur = queue.popleft()

    if cur == k:
        res = dist[cur]
        cnt += 1
        continue

    for i in (cur - 1, cur + 1, cur * 2):
        if 0 <= i < MAX_SIZE and (dist[i] == 0 or dist[i] == dist[cur] + 1):
            dist[i] = dist[cur] + 1
            queue.append(i)

print(res)
print(cnt)
