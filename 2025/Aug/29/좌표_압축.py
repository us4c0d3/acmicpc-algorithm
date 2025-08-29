from sys import stdin as s
input = lambda: s.readline().rstrip()

# main code
n = int(input())
x = [*map(int, input().split())]
sorted_x = sorted(list(set(x)))
x_idx = {sorted_x[i]: i for i in range(len(sorted_x))}

res = []
for i in x:
    res.append(x_idx[i])

print(*res)
