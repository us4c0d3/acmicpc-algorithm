import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())
li = input()

for k in range(1, n + 1):
    s = set()
    for i in range(n - k + 1):
        s.add(li[i:i+k])
    if len(s) == n - k + 1:
        print(k)
        break