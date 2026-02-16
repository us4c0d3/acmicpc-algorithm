import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
input()
res = 0
s = set()
for _ in range(n - 1):
    tmp = input()
    if tmp != 'ENTER':
        s.add(tmp)
    else:
        res += len(s)
        s = set()

print(res + len(s))
