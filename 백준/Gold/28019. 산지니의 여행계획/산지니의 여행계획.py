import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n, m = map(int, input().split())
parent = list(range(n + 1))
rank = [0] * (n + 1)
edges = []
for _ in range(m):
    edges.append([*map(int, input().split())])
edges.sort(key=lambda x: x[2], reverse=True)

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
            

mst = [[] for _ in range(n + 1)]
s = 0
for a, b, c in edges:
    if find(a) != find(b):
        union(a, b)
        s += c
        mst[a].append((b, c))
        mst[b].append((a, c))

def dfs(start):
    visited = [False] * (n + 1)
    stack = [(start, 0)]
    visited[start] = True
    
    res = 0
    cur = start
    while stack:
        cur, dist = stack.pop()
        
        if dist > res:
            res = dist
        
        for nxt, nxt_cost in mst[cur]:
            if not visited[nxt]:
                visited[nxt] = True
                stack.append((nxt, dist + nxt_cost))
                
    return res

print(2 * s - dfs(int(input())))
