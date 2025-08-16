import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())
s = input().rstrip()
t = input().rstrip()
chg = [0] * (n + 1)
for i in range(m):
    l, r = map(int, input().rstrip().split())
    chg[l - 1] ^= 1
    chg[r] ^= 1

flip = 0
res = []
for i in range(n):
    flip ^= chg[i]
    res.append(t[i] if flip else s[i])

print(''.join(res))
