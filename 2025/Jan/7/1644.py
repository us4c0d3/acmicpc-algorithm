import sys

input = sys.stdin.readline

def eratosthenes(n):
    a = [False, False] + [True] * (n - 1)
    primes = []

    for i in range(2, n + 1):
        if a[i]:
            primes.append(i)
            for j in range(2 * i, n + 1, i):
                a[j] = False
    return primes


n = int(input())
primes = eratosthenes(n)

l = r = 0
cnt = 0

while l <= r <= len(primes):
    nums = sum(primes[l:r])
    if nums == n:
        cnt += 1
        r += 1
    elif nums < n:
        r += 1
    else:
        l += 1

print(cnt)
