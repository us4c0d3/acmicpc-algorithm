import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
t = int(input())
for _ in range(t):
    input()
    n = int(input())
    candy = 0
    for i in range(n):
        candy += int(input())
    if candy % n == 0:
        print('YES')
    else:
        print('NO')