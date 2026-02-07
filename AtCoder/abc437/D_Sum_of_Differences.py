import sys
from bisect import bisect_left

input = lambda: sys.stdin.readline().rstrip()

# main code
n, m = map(int, input().split())
a = [*map(int, input().split())]
b = [*map(int, input().split())]
b.sort()

pref = [0] * (m + 1)
for i, x in enumerate(b, 1):
    pref[i] = pref[i - 1] + x

sumb = pref[m]
res = 0

for aa in a:
    pos = bisect_left(b, aa)
    left = pref[pos]
    right = sumb - left
    res += aa * pos - left + right - aa * (m - pos)
    res %= 998244353

print(res)