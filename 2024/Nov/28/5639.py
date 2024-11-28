import sys
sys.setrecursionlimit(10**5)

input = sys.stdin.readline

pre = []

while True:
    try:
        pre.append(int(input().rstrip()))
    except:
        break

def postorder(start, end):
    if start > end:
        return

    # TODO: 이 조건 재검토 필요
    s = pre[start]
    mid = end + 1
    for i in range(start + 1, end + 1):
        if s < pre[i]:
            mid = i
            break

    postorder(start + 1, mid - 1)
    postorder(mid, end)
    print(pre[start])


postorder(0, len(pre) - 1)
