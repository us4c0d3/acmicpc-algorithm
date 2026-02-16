from sys import stdin
input = lambda: stdin.readline().rstrip()

# main code
def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, rank, a, b):
    a = find(parent, a)
    b = find(parent, b)

    if a != b:
        if rank[a] > rank[b]:
            parent[b] = a
            return a
        elif rank[a] < rank[b]:
            parent[a] = b
            return b
        else:
            parent[b] = a
            rank[a] += 1
            return a
    return a


n = int(input())
a = [*map(int, input().split())]
parent = [i for i in range(n)]
rank = [0] * (n)
m = int(input())

val_to_group = {}
group_to_val = {}

for i, val in enumerate(a):
    if val not in val_to_group:
        val_to_group[val] = i
        group_to_val[i] = val
    else:
        prev = val_to_group[val]
        new = union(parent, rank, i, prev)
        val_to_group[val] = new
        if new not in group_to_val:
            group_to_val[new] = val
            del group_to_val[prev]            

for _ in range(m):
    q, *nums = map(int, input().split())
    if q == 1:
        if nums[0] not in val_to_group:
            continue

        xg = val_to_group[nums[0]]
        if nums[1] not in val_to_group:
            val_to_group[nums[1]] = xg
            group_to_val[xg] = nums[1]
            del val_to_group[nums[0]]
        else:
            yg = val_to_group[nums[1]]
            tmp = union(parent, rank, xg, yg)
            val_to_group[nums[1]] = tmp
            group_to_val[tmp] = nums[1]
            del val_to_group[nums[0]]
    else:
        res = find(parent, nums[0] - 1)
        print(group_to_val[res])
