import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())
m = int(input())

# kruskal
edges = []
parent = list(range(n + 1))
rank = [0] * (n + 1)
for _ in range(m):
    edges.append([*map(int, input().split())])
    
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a != b:
        if rank[a] < rank[b]:
            parent[a] = b
        elif rank[a] > rank[b]:
            parent[b] = a
        else:
            parent[b] = a
            rank[a] += 1

edges.sort(key=lambda x: x[2])
res = 0
for a, b, c in edges:
    if find(a) != find(b):
        union(a, b)
        res += c
print(res)
