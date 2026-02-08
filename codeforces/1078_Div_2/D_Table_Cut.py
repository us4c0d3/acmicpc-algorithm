import sys

input = lambda: sys.stdin.readline().rstrip()

# 왼위에서 오아 대각선으로 자르기
# 자르는 경로를 RD를 이용해 출력
# grid 입력값은 모두 0 또는 1
# 잘랐을 때 나뉘는 값의 합의 곱 최댓값

# main code
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    grid = [[] for _ in range(n)]
    for i in range(n):
        grid[i] = [*map(int, input().split())]
