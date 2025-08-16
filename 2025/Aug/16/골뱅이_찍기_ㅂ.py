from sys import stdin as s
input = lambda: s.readline().rstrip()

n = int(input())

for i in range(n * 5):
    if i < n * 2:
        print('@' * n + ' ' * n * 3 + '@' * n)
    elif n * 3 <= i < n * 4:
        print('@' * n + ' ' * n * 3 + '@' * n)
    else:
        print('@' * n * 5)
