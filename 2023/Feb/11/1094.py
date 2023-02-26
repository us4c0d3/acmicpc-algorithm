X = int(input())

stick = [64, 32, 16, 8, 4, 2, 1]
n = 0
t = 0

for i in range(len(stick)):
    if stick[i] <= X:
        X -= stick[i]
        n += 1

print(n)