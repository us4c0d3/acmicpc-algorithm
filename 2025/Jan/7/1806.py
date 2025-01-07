import sys

input = sys.stdin.readline

n, s = map(int, input().split())
li = list(map(int, input().split()))

start = end = 0
min_length = n + 2
total = li[0]

while start <= end <= n:
    length = end - start + 1

    if total >= s:
        min_length = min(min_length, length)
        total -= li[start]
        start += 1
    else:
        end += 1
        if end < n:
            total += li[end]
        else:
            break
if min_length == n + 2:
    print(0)
else:
    print(min_length)
