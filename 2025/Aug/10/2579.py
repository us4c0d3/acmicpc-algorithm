import sys
input = sys.stdin.readline

n = int(input())
stair = [0] * 300
for i in range(n):
    stair[i] = int(input())

# 도착위치 n에서 가능한 경우의 수
# 2번 조건에 의해 n-2, n-1, n은 불가능
# n - 2, n
# n - 3, n - 1, n
# dp[n] = dp[n - 2] + stair[n]
# dp[n] = dp[n - 3] + stair[n - 1] + stair[n]

dp = [0] * 300
dp[0] = stair[0]
dp[1] = stair[0] + stair[1]
dp[2] = max(stair[1] + stair[2], stair[0] + stair[2])

for i in range(3, n):
    dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i])

print(dp[n - 1])
