import sys

input = sys.stdin.readline

n = int(input())
time = []
res = []
for i in range(n):
    time.append(tuple(map(int, input().split())))

time.sort(key=lambda x: (x[1], x[0]))
res.append(time[0])
for i in range(1, n):
    if time[i][0] >= res[-1][1]:
        res.append(time[i])

print(len(res))
