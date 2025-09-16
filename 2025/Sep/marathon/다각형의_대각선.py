import sys
import math

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())
def solve():
    if n == 3:
        print(0)
        return
    print(math.factorial(n) // (math.factorial(n - 4) * 24))

solve()