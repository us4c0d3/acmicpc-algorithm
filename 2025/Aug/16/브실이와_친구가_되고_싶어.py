from sys import stdin as s
input = lambda: s.readline().rstrip()

a, b = map(int, input().split())
k, x = map(int, input().split())

# [k - x, k + x]
res = 0
l = k - x
r = k + x
if l < a:
    l = a
if r > b:
    r = b

for i in range(l, r + 1):
    res += 1
print(res if res != 0 else 'IMPOSSIBLE')