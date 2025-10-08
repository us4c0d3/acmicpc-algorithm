from sys import stdin as s
input = lambda: s.readline().rstrip()

# main code
n, budget, hotel, week = map(int, input().split())
avail = []
for _ in range(hotel):
    price = int(input())
    people = max(map(int, input().split()))
    avail.append([price, people])

avail.sort(key=lambda x: x[0])
res = -1
for price, people in avail:
    if people >= n:
        res = price * n
        break
if res == -1 or res > budget:
    print('stay home')
else:
    print(res)
    