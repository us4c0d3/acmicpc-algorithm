import sys

input = lambda: sys.stdin.readline().rstrip()

INF = int(1e9)

"""
모든 맨해튼 거리를 다 구하고 이를 기반으로 shortest path
n = 500 -> 모든 거리를 다 구하는 경우의 수 (500 * 499 = 250000 - 500) -> 가능
k 조건 사용 어려움

dp
dp[i][j]: i위치, j번 건너뜀
dp[i][j] = min(dp[i][j], dp[prev][j - (i - prev - 1)] + dist[prev][i])
i - prev + 1 = skip
prev = i - skip + 1
"""


def get_dist(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

n, k = map(int, input().split())
points = [[*map(int, input().split())] for _ in range(n)]
dp = [[INF] * (k + 1) for _ in range(n)]
dp[0][0] = 0

dist = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(n):
    for j in range(n):
        dist[i][j] = dist[j][i] = get_dist(*points[i], *points[j])

for i in range(1, n):
    for j in range(k + 1):
        for skip in range(j + 1):
            prev = i - skip - 1
            if prev < 0: break
            dp[i][j] = min(dp[i][j], dp[prev][j - skip] + dist[prev][i])

print(dp[n - 1][k])
