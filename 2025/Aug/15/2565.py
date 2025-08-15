import sys
input = sys.stdin.readline

n = int(input())
line = []
dp = [1] * 101
for i in range(n):
    a, b = map(int, input().rstrip().split())
    line.append((a, b))

line.sort(key=lambda x: x[0])
for i in range(1, n):
    for j in range(i):
        if line[j][1] < line[i][1]:
            dp[i] = max(dp[i], dp[j] + 1)

print(n - max(dp))
