import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
tmp = 9 * 1 + 7 * 3 + 8 * 1 + 0 * 3 + 9 * 1 + 2 * 3 + 1 * 1 + 4 * 3 + 1 * 1 + 8 * 3
t = int(input())
tmp += t
t = int(input())
tmp += t * 3
t = int(input())
tmp += t
print(f'The 1-3-sum is {tmp}')