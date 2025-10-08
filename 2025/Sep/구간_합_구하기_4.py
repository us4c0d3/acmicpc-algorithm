from sys import stdin as s
input = lambda: s.readline().rstrip()

# main code
n, m = map(int, input().split())
li = [0, *map(int, input().split())]
memo = [0] * (n + 1)
for i in range(1, n + 1):
    memo[i] = memo[i - 1] + li[i]

for _ in range(m):
    i, j = map(int, input().split())
    print(memo[j] - memo[i - 1])
