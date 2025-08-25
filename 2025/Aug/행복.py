from sys import stdin as s
input = lambda: s.readline().rstrip()

# main code
n = input()
score = [*map(int, input().split())]
print(max(score) - min(score))
