from sys import stdin as s
input = lambda: s.readline().rstrip()

x = int(input())
y = int(input())

for i in range(x):
    for j in range(y):
        print('*', end='')
    print()