import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
t = int(input())

def solve(a, b, c):
    res = 0
    # abc
    m = min(a, b, c)
    a, b, c = a - m, b - m, c - m
    res = m
    
    # aac, acc -> bbs or sbb
    big, small = a, c
    if big < small:
        big, small = small, big
    if small == 0:
        pass
    elif big >= 2 * small:
        # bbs
        res += small
    else: # s <= b < 2 * s
        # bbs, bss
        tmp = big - small
        res += tmp
        big -= 2 * tmp
        small -= tmp
        res += (big + small) // 3
    
    print(res)



for _ in range(t):
    a, b, c = map(int, input().split())
    solve(a, b, c)


# --- Editorial

# def solve(a, b, c):
#     print(min(a, c, (a + b + c) // 3))