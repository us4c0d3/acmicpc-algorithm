import sys

input = lambda: sys.stdin.readline().rstrip()
INF = 10 ** 9

# main code
n = int(input())
arr = [*map(int, input().split())]

dp = [-INF] * n
dp[0] = arr[0]
for i in range(1, n):
    dp[i] = max(dp[i - 1] + arr[i], arr[i])

print(max(dp))
