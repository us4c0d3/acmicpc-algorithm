import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a != b:
        if rank[a] > rank[b]:
            parent[b] = a
        elif rank[a] < rank[b]:
            parent[a] = b
        else:
            parent[b] = a
            rank[a] += 1

n, m = map(int, input().split())
parent = [i for i in range(n)]
rank = [0] * n

for cur in range(1, m + 1):
    a, b = map(int, input().split())
    if find(a) == find(b):
        print(cur)
        exit()
    else:
        union(a, b)

print(0)
