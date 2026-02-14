import sys
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()

# main code
h, w, n = map(int, input().split())
pieces = []
hs = defaultdict(list)
ws = defaultdict(list)
for i in range(n):
    hh, ww = map(int, input().split())
    pieces.append((hh, ww))
    hs[hh].append(i)
    ws[ww].append(i)

# 총 합이 H 및 W
# 회전 불가
# 순서대로 잘라서 둘 중 하나만 내려둠
# 무조건 H또는 W인 초콜릿 존재
# 줄여나가는 식으로 역순 ㄱ => stack

used = [False] * n
res = [None] * n

cur_x, cur_y = 1, 1
cur_h, cur_w = h, w

for _ in range(n):
    flag = False
    
    while ws[cur_w]:
        idx = ws[cur_w].pop()
        if used[idx]:
            continue
        hh, ww = pieces[idx]
        res[idx] = (cur_x, cur_y)
        cur_x += hh
        cur_h -= hh
        used[idx] = True
        flag = True
        break

    if flag:
        continue

    while hs[cur_h]:
        idx = hs[cur_h].pop()
        if used[idx]:
            continue
        hh, ww = pieces[idx]
        res[idx] = (cur_x, cur_y)
        cur_y += ww
        cur_w -= ww
        used[idx] = True
        break

for pos in res:
    print(pos[0], pos[1])
