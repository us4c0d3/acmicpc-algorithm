import sys

input = lambda: sys.stdin.readline().rstrip()
INF = 10 ** 9

# main code
n = int(input())
graph = [[0] * (n + 2) for _ in range(n + 2)]
for i in range(1, n + 1):
    link = [*map(int, input().split())]
    link = link[:-1]
    for x in link:
        graph[i][x] = 1

prefix = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, n + 1):
        prefix[i][j] = graph[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]

# n * (n - 1) // 2 - prefix(--+)(1, i - 1) + prefix(--+)(i, j)
# 1. dp[i - 1] + i를 별개의 모둠으로 처리했을 때
#   i가 연결된 간선개수
# 2. dp[i - 1] + i를 직전 모둠으로 처리했을 때
#   직전 모둠의 시작 인덱스를 j라고 했을 때 dp[i][j]로 저장
# 1차원으로 역방향 순회를 하면 dp[j]

dp = [INF] * (n + 2)
dp[n + 1] = 0

def get_edges(x1, y1, x2, y2):
    return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1]

def get_cost(i, j):
    m = j - i + 1
    left_sum = m * (m - 1) // 2 - get_edges(i, i, j, j) // 2
    right_sum = get_edges(i, j + 1, j, n)
    return left_sum + right_sum

nxt = [-1] * (n + 2)
for i in range(n, 0, -1):
    best = INF
    best_j = i
    for j in range(i, n + 1):
        val = get_cost(i, j) + dp[j + 1]
        if best > val:
            best = val
            best_j = j
    dp[i] = best
    nxt[i] = best_j

idx = 1
res = []
while idx <= n:
    j = nxt[idx]
    res.append(j - idx + 1)
    idx = j + 1

print(dp[1])
print(len(res), *res)
