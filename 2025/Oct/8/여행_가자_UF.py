import sys
from sys import stdin
sys.setrecursionlimit(100000)
input = lambda: stdin.readline().rstrip()

# main code
n = int(input())
m = int(input())
unf = [i for i in range(n + 1)]

def find(x):
    if unf[x] == x:
        return x
    unf[x] = find(unf[x])
    return unf[x]

def union(a, b):
    fa, fb = find(a), find(b)
    if fa > fb:
        unf[fa] = fb
    else:
        unf[fb] = fa

grid = [[] for _ in range(n)]
for i in range(n):
    tmp = [*map(int, input().split())]
    for j in range(n):
        if tmp[j]:
            union(i, j)

def solve():
    plan = [*map(int, input().split())]
    for i in range(1, m):
        if unf[plan[0] - 1] != unf[plan[i] - 1]:
            print('NO')
            return

    print('YES')

solve()
