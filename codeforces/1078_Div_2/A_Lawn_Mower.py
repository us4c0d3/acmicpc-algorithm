import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
t = int(input())
for _ in range(t):
    n, w = map(int, input().split())
    # 사이에는 하나씩 남겨야됨
    # w-1 이하 개수 최대를 구해야함
    # 블록 단위 -> w마다 1개 남음
    if w == 1:
        print(0)
        continue

    print(n - n // w)
