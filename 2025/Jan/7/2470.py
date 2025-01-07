import sys

input = sys.stdin.readline

n = int(input())
li = sorted(map(int, input().split()))

s = 0
e = n - 1
m = abs(li[s] + li[e])
res = [li[s], li[e]]

while s != e and e >= 0 and s < n:
    tmp = li[s] + li[e]

    if abs(tmp) < m:
        m = abs(tmp)
        res = [li[s], li[e]]
        if m == 0:
            break

    if tmp < 0:
        s += 1

    else:
        e -= 1


print(res[0], res[1])
