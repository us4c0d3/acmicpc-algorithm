import sys

input = lambda: sys.stdin.readline().rstrip()

# primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]
# best_divs = 0
# best_num = 0
# def dfs(idx, max_e, num, divs):
#     global best_divs, best_num
#     if divs > best_divs or (divs == best_divs and num < best_num):
#         best_divs, best_num = divs, num
#     if idx == len(primes):
#         return
#     p = primes[idx]
#     v = num
#     for e in range(1, max_e + 1):
#         v *= p
#         if v > 50_000:
#             break
#         dfs(idx + 1, e, v, divs * (e + 1))
# dfs(0, 100, 1, 1)
# print(best_num, best_divs)

# 문제 이해
# k개의 문자열의 i번째에서는 최대 k개의 선택지가 존재
# 그 선택지들을 뽑아서 만든 최종 문자열 출력
# 문자열 선택은 길이가 d인 주기가 최대가 되도록
# d가 최솟값이 되도록 만들자
# 어떻게

# d의 경우의 수; n의 약수
# d의 경우의 수로 완전탐색?
# 2 <= n, k <= 50000, 4 <= n*k <= 10^5
# 50000까지 수 중 약수 최댓 개수 => 100 ; d 후보 수
# 알파벳 26개 비트연산
# 입력 처리 비트로
# 50000 * 100 = 5_000_000 => 가능
# 그런데 약수를 구하는 시간복잡도?
# n % d == 0으로 처리 => 무시

# 구현 ㄱ


# main code
def get_chr_from_bit(mask):
    lsb = mask & -mask
    idx = lsb.bit_length() - 1
    return chr(ord('a') + idx)

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    mask = [0] * n
    for _ in range(k):
        s = input()
        for i, ch in enumerate(s):
            mask[i] |= 1 << (ord(ch) - ord('a'))
    
    for d in range(1, n + 1):
        if n % d != 0:
            continue

        tmp = [(1 << 26) - 1] * d
        for i in range(n):
            tmp[i % d] &= mask[i]

        chk = True
        for v in tmp:
            if v == 0:
                chk = False
                break
                
        if chk:
            pattern = ''.join(get_chr_from_bit(v) for v in tmp)
            res = pattern * (n // d)
            print(res)
            break
