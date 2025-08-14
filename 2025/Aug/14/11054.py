import sys
input = sys.stdin.readline

n = int(input())
li = list(map(int, input().rstrip().split()))
li_rev = li[::-1]
dp1 = [0] * n
dp2 = [0] * n

for i in range(n):
    dp1[i] = 1
    dp2[i] = 1
    for j in range(i):
        if li[i] > li[j]:
            dp1[i] = max(dp1[i], dp1[j] + 1)
        if li_rev[i] > li_rev[j]:
            dp2[i] = max(dp2[i], dp2[j] + 1)

res = [0] * n
for i in range(n):
    res[i] = dp1[i] + dp2[n - 1 - i] - 1

print(max(res))
