import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break

    print(min(30*a + 40*b, 35*a + 30*b, 40*a + 20*b))