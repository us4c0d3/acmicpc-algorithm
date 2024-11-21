import sys

input = sys.stdin.readline

n = int(input().rstrip())
size_list = list(map(int, input().rstrip().split()))
t, p = map(int, input().rstrip().split())

res_t = 0

for i in range(6):
    v, r = divmod(size_list[i], t)
    if r != 0:
        v += 1
    res_t += v

res_p = divmod(n, p)
print(res_t)
print(*res_p)
