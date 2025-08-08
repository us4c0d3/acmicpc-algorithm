import sys
input = sys.stdin.readline

n = int(input())
length = list(map(int, input().rstrip().split()))
price = list(map(int, input().rstrip().split()))
result = 0
cost = float("inf")

for i in range(n - 1):
    if cost > price[i]:
        cost = price[i]
    result += cost * length[i]

print(result)
