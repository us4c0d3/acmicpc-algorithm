from sys import stdin
input = lambda: stdin.readline().rstrip()

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
edges = []
parent = [i for i in range(n + 1)]
rank = [0] * (n + 1)
for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((c, a, b))

edges.sort()
res = 0
max_edge = 0
for c, a, b in edges:
    if find(a) != find(b):
        union(a, b)
        res += c
        max_edge = c

print(res - max_edge)
