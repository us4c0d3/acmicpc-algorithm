from sys import stdin
from collections import defaultdict
input = lambda: stdin.readline().rstrip()

# main code
n = int(input())
sizes = [*map(int, input().split())]

# Q * T 합의 최댓값
# T가 최대한 길어지게
# (Q - W + 1 = T)라는 조건의 의미 -> 각 인형은 서로 크기가 1씩 차이나야 함
# 점수는 Q * T => Q * (Q - W + 1)
# => 수의 개수로 저장시켜서 빼는 식으로 하자
# 어떻게?
# 결국 cnt가 문제
# 수열 시작과 종료는 freq의 개수 변화에 따라 존재
# cur보다 prev가 크면 수열 시작
# prev가 cur보다 크면 수열 종료

freq = defaultdict(int)
Max = 0
for size in sizes:
    freq[size] += 1
    if size > Max:
        Max = size

res = 0
qs = []
for i in range(Max, -1, -1):
    prev = freq[i + 1]
    cur = freq[i]

    if cur > prev:  # 수열 시작
        for _ in range(cur - prev):  # 시작할 수 있는 수열 개수
            qs.append(i)
    elif cur < prev:  # 수열 종료
        for _ in range(prev - cur):  # 종료됐을 때의 수열 개수
            q = qs.pop()
            res += q * (q - (i + 1) + 1)

print(res)
