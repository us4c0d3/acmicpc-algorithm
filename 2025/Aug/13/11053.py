import sys
input = sys.stdin.readline

n = int(input())
li = list(map(int, input().rstrip().split()))
dp = [0] * n

for i in range(n):
    dp[i] = 1
    for j in range(i):
        if li[i] > li[j]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))
