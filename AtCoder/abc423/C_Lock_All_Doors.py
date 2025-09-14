import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n, r = map(int, input().split())
doors = [*map(int, input().split())]

# 0의 개수 + r으로부터 닿지 못하는 위치에서 2번 조작해야되는 위치의 개수
def solve():
    zeros = [i for i, v in enumerate(doors, start=1) if v == 0]
    if not zeros:
        print(0)
        return

    cnt = len(zeros)

    l_end, r_end = min(zeros), max(zeros)
    pref = [0] * (n + 1)
    for i in range(1, n + 1):
        pref[i] = pref[i - 1] + (1 if doors[i - 1] == 1 else 0)

    def rooms(a, b):
        lo, hi = sorted((a, b))
        return pref[hi] - pref[lo]
    
    extra = 0
    if l_end <= r <= r_end - 1:
        extra = rooms(l_end, r_end)
    else:
        extra = rooms(l_end, r_end) + min(rooms(r, l_end), rooms(r, r_end))
    res = cnt + 2 * extra

    print(res)

solve()