from sys import stdin as s
input = lambda: s.readline().rstrip()

# main code
n, k = map(int, input().split())
temp = [*map(int, input().split())]
prefix = [0] * n
prefix[0] = temp[0]
for i in range(1, n):
    prefix[i] = prefix[i - 1] + temp[i]

res = [prefix[k - 1]]
for i in range(k, n):
    res.append(prefix[i] - prefix[i - k])

print(max(res))
