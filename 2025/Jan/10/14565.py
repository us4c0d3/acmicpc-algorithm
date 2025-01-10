n, a = map(int, input().split())

try:
    mul_inv = pow(a, -1, n)
except ValueError:
    mul_inv = -1

print(n - a, mul_inv)
