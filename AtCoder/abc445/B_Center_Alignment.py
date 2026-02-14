import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())
strs = []
max_len = 0
for _ in range(n):
    tmp = input()
    strs.append(tmp)
    max_len = max(max_len, len(tmp))


for s in strs:
    res = f'{s:.^{max_len}}'
    print(res)