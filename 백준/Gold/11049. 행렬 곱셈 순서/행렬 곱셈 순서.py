from sys import stdin
input = lambda: stdin.readline().rstrip()

INF = 2147483647

# 구간 dp 기본 문제

# main code
n = int(input())
mats = [[*map(int, input().split())] for _ in range(n)]

dp = [[0] * n for _ in range(n)]

# dp[i][j]: i부터 j까지 행렬 곱의 최솟값
# dp[i][j] = min(dp[i][k] + dp[k + 1][j] + r_i * c_k * c_j)
for dist in range(1, n):  # 구간 거리
    for i in range(n - dist):
        j = i + dist
        dp[i][j] = INF  # 초기값 최대

        for k in range(i, j):
            cost = dp[i][k] + dp[k + 1][j] + (mats[i][0] * mats[k][1] * mats[j][1])
            if cost < dp[i][j]:
                dp[i][j] = cost
        
print(dp[0][n-1])