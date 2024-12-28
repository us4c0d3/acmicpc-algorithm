import sys

input = sys.stdin.readline

n = int(input())
m = {}
idx = 0
s = input().rstrip().split()
for i in range(n):
    if s[i] not in m:
        m[s[i]] = 1
    else:
        m[s[i]] += 1
        if m[s[i]] >= 5:
            idx = i + 1
            break

print(idx)
