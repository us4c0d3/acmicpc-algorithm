import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n, m = map(int, input().split())

# 하나의 행에 대해서
# k번 스위치 클릭
# 1. k와 꺼져있는 램프 수(0)의 개수가 동일할 때
# 2. k보다 0의 개수가 작을 때 -> 껐다가 켜야되니까(짝수) (k - (0의 개수))가 짝수
# -> 홀짝이 맞아야된다

# 이것과 동일한 경우의 행 개수를 구하면 된다
# 1번 케이스는 0의 위치가 k와 완전히 동일


res = 0
grid = [input() for _ in range(n)]
k = int(input())
for i in range(n):
    tmp = 0
    cnt = grid[i].count('0')
    if cnt <= k and cnt % 2 == k % 2:
        for j in range(i, n):
            # 1번 케이스
            if grid[i] == grid[j]:
                tmp += 1
    res = max(res, tmp)

print(res)
