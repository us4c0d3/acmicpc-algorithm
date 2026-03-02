import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())

# f(n) = f(n - 1) + f(n - 2)

dp = [0, 1, 2]
for i in range(3, n + 1):
    dp.append(dp[i - 1] + dp[i - 2])

print(dp[n] % 10007)