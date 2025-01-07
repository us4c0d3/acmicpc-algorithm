import sys

input = sys.stdin.readline

n, m = map(int, input().rstrip().split())

li = list(map(int, input().rstrip().split()))

s = e = 0
cnt = 0

while s <= e <= n:
    total = sum(li[s:e])

    if total == m:
        cnt += 1
        e += 1

    elif total < m:
        e += 1

    else:
        s += 1

print(cnt)
