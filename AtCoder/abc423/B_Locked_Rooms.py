import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())
li = [*map(int, input().split())]

def solve():
    cnt = n - 2 + 1
    for i in range(n):
        if li[i] == 1:
            break
        cnt -= 1

    for i in range(n - 1, -1, -1):
        if li[i] == 1:
            break
        cnt -= 1
    
    print(cnt if cnt >= 0 else 0)

solve()