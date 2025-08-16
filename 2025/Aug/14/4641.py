import sys
input = sys.stdin.readline

while True:
    tc = list(map(int, input().rstrip().split()))
    if tc[0] == -1:
        break
    print(sum(1 for v in tc if v * 2 in tc) - 1)
