import sys
from collections import deque

input = sys.stdin.readline
MAX_SIZE = 100001

n, k = map(int, input().split())
visited = [False] * MAX_SIZE
dist = [MAX_SIZE] * MAX_SIZE
queue = deque()

visited[n] = True
dist[n] = 0
queue.append(n)

res = 0


def isValid(data):
    if data < 0 or data >= MAX_SIZE or visited[data] is True:
        return False
    else:
        return True


cnt = 0

while queue:
    cur = queue.popleft()

    if cur == k:
        res = dist[cur]
        cnt += 1
        continue

    if isValid(cur * 2):
        visited[cur * 2] = True
        dist[cur * 2] = dist[cur] + 1
        queue.append(cur * 2)

    if isValid(cur - 1):
        visited[cur - 1] = True
        dist[cur - 1] = dist[cur] + 1
        queue.append(cur - 1)

    if isValid(cur + 1):
        visited[cur + 1] = True
        dist[cur + 1] = dist[cur] + 1
        queue.append(cur + 1)

print(res)
print(cnt)
