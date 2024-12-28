import sys

input = sys.stdin.readline
a, b = map(int, input().rstrip().split())
tmp = (a + b) % 4

if tmp == 0:
    tmp = 4

c, d = map(int, input().rstrip().split())
second = (c + d + tmp - 1) % 4

if second == 0:
    second = 4

print(second)
