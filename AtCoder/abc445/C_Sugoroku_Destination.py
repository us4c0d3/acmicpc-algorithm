import sys
sys.setrecursionlimit(10 ** 6)

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())
a = [0] + [*map(int, input().split())]

def find(x):
    if a[x] != x:
        a[x] = find(a[x])
    return a[x]

res = []
for i in range(1, n + 1):
    res.append(str(find(i)))

print(" ".join(res))
