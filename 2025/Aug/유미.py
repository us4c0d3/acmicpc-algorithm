from sys import stdin as s
import math
import itertools
input = lambda: s.readline().rstrip()

# main code
yumi = [*map(int, input().split())]
people = [[*map(int, input().split())] for _ in range(3)]
res = float('inf')

dest = lambda a, b : math.sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2))

for loc in itertools.permutations(people):
    d = dest(yumi, loc[0]) + dest(loc[0], loc[1]) + dest(loc[1], loc[2])
    res = min(res, d)

print(math.floor(res))