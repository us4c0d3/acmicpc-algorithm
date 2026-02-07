import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n = [*input()]
for x in range(2):
    if n[x] != n[x+1]:
        print('No')
        break
else:
    print('Yes')