import sys
input = sys.stdin.readline

n = int(input())
memo = [1, 1, 2, 6]

def factorial(n):
    if n < 4:
        return memo[n]

    factorial(n - 1)
    memo.append(memo[n - 1] * n)
    return memo[n]


print(factorial(n))
