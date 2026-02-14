import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
s = input()
if s[0] == s[-1]:
    print('Yes')
else:
    print('No')