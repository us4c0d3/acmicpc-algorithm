import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
x, c = map(int, input().split())
# 1000당 c
res = x // (1000 + c) * 1000
print(res)