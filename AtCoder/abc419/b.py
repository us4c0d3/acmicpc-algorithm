import sys
input = sys.stdin.readline

n = int(input())
l = []

for i in range(n):
    t = list(map(int, input().rstrip().split()))
    if len(t) == 2:
        l.append(t[1])
    else:
        m = min(l)
        print(m)
        l.remove(m)
