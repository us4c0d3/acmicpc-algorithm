import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
def solve():
    res = 0
    n = int(input())
    power = 0
    cost = []
    for _ in range(n):
        w, p = map(int, input().split())
        power += p
        cost.append(w + p)

    cost.sort()
    cur = 0
    for c in cost:
        if cur + c <= power:
            cur += c
            res += 1
        else:
            break

    return res

t = int(input())
for _ in range(t):
    print(solve())