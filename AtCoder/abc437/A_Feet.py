import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
a, b = map(int, input().split())
print(a*12 + b)