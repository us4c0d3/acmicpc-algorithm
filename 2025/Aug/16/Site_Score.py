from sys import stdin as s
input = lambda: s.readline().rstrip()

a, b, c, d = map(int, input().split())
print(56 * a + 24 * b + 14 * c + 6 * d)
