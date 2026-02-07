import sys

input = lambda: sys.stdin.readline().rstrip()
# max = 2 * 10 ** 5
# 최대 증가 max + 5

# main code
n = int(input())
a = [*map(int, input().split())]
a.sort(reverse=True)

maxa = max(a)
cnt = [0] * (maxa + 1)
for x in a:
    cnt[x] += 1
nums = [0] * (maxa + 6)

# TLE
# 2*10^5 * 2*10^5 = 4*10^10 => 40sec
# for x in a:
#     tmp = x
#     while tmp > 0:
#         nums[tmp] += 1
#         tmp -= 1

tmp = 0
for i in range(maxa, 0, -1):
    tmp += cnt[i]
    nums[i] = tmp

for i in range(1, maxa+4):
    if nums[i] >= 10:
        nums[i + 1] += nums[i] // 10
        nums[i] %= 10

idx = maxa + 5
while idx > 1 and nums[idx] == 0:
    idx -= 1

print(''.join((str(nums[i])) for i in range(idx, 0, -1)))
