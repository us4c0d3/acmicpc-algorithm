from sys import stdin as s
import math
input = lambda: s.readline().rstrip()

# main code
x = [*map(int, input().split())]
y = [*map(int, input().split())]

d = math.sqrt((x[0] - y[0])**2 + (x[1]-y[1])**2)
if d < x[2] + y[2]:
    print('YES')
else:
    print('NO')
    