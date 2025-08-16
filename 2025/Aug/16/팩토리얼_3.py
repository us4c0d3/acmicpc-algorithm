from sys import stdin as s
input = lambda: s.readline().rstrip()

n = int(input())
res = 1
for i in range(1, n + 1):
    res *= i
print(res)
