from sys import stdin as s
input = lambda: s.readline().rstrip()

# main code
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    print((a // b) ** 2)
