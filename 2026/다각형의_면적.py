import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())
point = [[] for _ in range(n)]
for i in range(n):
    point[i] = [*map(int, input().split())]
point.append(point[0])

res = 0
for i in range(n):
    res += point[i][0] * point[i+1][1] - point[i+1][0] * point[i][1]

print(abs(res)/2)