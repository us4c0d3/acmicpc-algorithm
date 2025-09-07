import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
s = input()
res = ""
if ord(s[2]) - ord('0') < 8:
    res = s[0] + s[1] + chr(ord(s[2]) + 1)
else:
    res = chr(ord(s[0]) + 1) + "-1"

print(res)