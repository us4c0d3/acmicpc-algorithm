import sys
input = sys.stdin.readline

s = input().rstrip()
if s == 'red':
    print('SSS')
elif s == 'blue':
    print('FFF')
elif s == 'green':
    print('MMM')
else:
    print('Unknown')
