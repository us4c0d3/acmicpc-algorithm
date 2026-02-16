from sys import stdin
input = lambda: stdin.readline().rstrip()

# main code
n, c = map(int, input().split())
houses = [int(input()) for _ in range(n)]
houses.sort()

def check(dist):
    cnt = 1
    last = houses[0]

    for i in range(1, n):
        if houses[i] - last >= dist:
            cnt += 1
            last = houses[i]
    
    return cnt >= c

start = 1
end = houses[-1] - houses[0]
res = 0

while start <= end:
    mid = (start + end) // 2

    if check(mid):
        res = mid
        start = mid + 1
    else:
        end = mid - 1

print(res)
