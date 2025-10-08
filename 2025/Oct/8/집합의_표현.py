import sys
from sys import stdin
sys.setrecursionlimit(100000)
input = lambda: stdin.readline().rstrip()

# main code
n, m = map(int, input().split())
unf = [i for i in range(n + 1)]

def find(x):
    if unf[x] == x:
        return x
    
    unf[x] = find(unf[x])
    return unf[x]


def union(a, b):
    fa, fb = find(a), find(b)
    if fa != fb:
        unf[fa] = fb



for _ in range(m):
    op, a, b = map(int, input().split())
    if op == 0:
        union(a, b)
    elif op == 1:
        if find(a) == find(b):
            print('yes')
        else:
            print('no')