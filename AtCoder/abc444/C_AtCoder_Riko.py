import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())
a = [*map(int, input().split())]

# 3 -> 4 4 4
# l = 4 홀수 개수이므로 8안됨

# 6
# 10 187 344 100 434 257
# 일단 최댓값으로 모두 만들 수 없음
# 숫자를 2개씩 더했을 때 444를 만들 수 있음

# l후보: 최댓값
# l > 최댓값: 제일 작은거 + 최댓값
# 찾은 후 검증

a.sort()
res = []
def is_ok(l):
    global res
    i, j = 0, n - 1
    while i < j:
        if a[j] == l:
            j -= 1
        else:
            if a[i] + a[j] != l:
                return False
            i += 1
            j -= 1
    if i == j:
        return a[i] == l
    return True


m, M = a[0], a[-1]
if is_ok(M):
    res.append(a[-1])

if M != m + M and is_ok(m + M):
    res.append(m + M)

res.sort()
print(*res)
