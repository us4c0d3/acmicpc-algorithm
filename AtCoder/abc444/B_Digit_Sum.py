import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n, k = [*map(int, input().split())]
res = 0

for i in range(1, n+1):
    sum = 0
    tmp = i
    while tmp > 0:
        sum += tmp % 10
        tmp //= 10
    if sum == k:
        res += 1
print(res)