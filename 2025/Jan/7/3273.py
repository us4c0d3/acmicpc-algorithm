import sys

input = sys.stdin.readline

n = int(input())
li = sorted(list(map(int, input().rstrip().split())))
x = int(input())

s = 0
e = n - 1
cnt = 0

while s < e < n:
    sums = li[s] + li[e]
    if sums == x:
        cnt += 1
        s += 1

    elif sums > x:
        e -= 1

    else:
        s += 1


print(cnt)
