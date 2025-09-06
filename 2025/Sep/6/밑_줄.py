import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n, m = map(int, input().split())
strings = []
length = 0
for i in range(n):
    tmp = input()
    length += len(tmp)
    strings.append(tmp)


base = (m - length) // (n - 1)
mod = (m - length) % (n - 1)

res = strings[0]

for i in range(1, n):
    if 'a' <= strings[i][0] <= 'z' and mod > 0:
        res += '_' * (base + 1)
        mod -= 1
    elif mod == (n - 1) - i + 1:
        res += '_' * (base + 1)
        mod -= 1
    else:
        res += '_' * base
    
    res += strings[i]

print(res)