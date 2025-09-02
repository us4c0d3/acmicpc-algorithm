from sys import stdin as s
import sys
sys.setrecursionlimit(100000)
input = lambda: s.readline().rstrip()

# main code
k = int(input())

def dfs(s):
    global chk

    for x in graph[s]:
        if visited[x] == 0:
            if visited[s] == 1:
                visited[x] = 2
            
            elif visited[s] == 2:
                visited[x] = 1
            
            dfs(x)
        
        else:
            if visited[s] == visited[x]:
                chk = False
                return
    

while k:
    k -= 1
    v, e = map(int, input().split())
    visited = [0] * (v + 1)
    chk = True

    graph = [[] for _ in range(v + 1)]
    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    for i in range(1, v + 1):
        if visited[i] == 0:
            visited[i] = 1
            dfs(i)

    if chk:
        print('YES')
    else:
        print('NO')