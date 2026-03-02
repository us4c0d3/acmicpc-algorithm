import sys

input = lambda: sys.stdin.readline().rstrip()
INF = 10 ** 9

# main code
n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]
dp = [INF] * (k + 1)
dp[0] = 0

for i in range(n):
    for j in range(coins[i], k + 1):
        dp[j] = min(dp[j], dp[j - coins[i]] + 1)

print(dp[k] if dp[k] != INF else -1)
