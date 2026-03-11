MOD = int(1e9) + 9

# 1. counter 트리거를 최대한 발생시키지 않음
# 2. greedy하게 풀이 -> k - 1까지 정답을 세자
# 최초 한번만 트리거 발생이 필연적인지만 체크하고 바로 결과 출력 가능

def power(a, n, mod):
    if n == 0:
        return 1
    half = power(a, n // 2, mod)
    if n & 1:
        return (half * half * a) % mod
    return (half * half) % mod

T = int(input())
for _ in range(T):
    n, m, k = map(int, input().split())
    wrong = n - m
    if m <= (k - 1) * (wrong + 1):
        print(m % MOD)
    else:
        back = (k - 1) * wrong
        trigger = (m - back) // k
        term1 = (power(2, trigger + 1, MOD) - 2) * k  # 등비수열의 합; (2 * (2^T - 1) // 2 - 1) == pow(2, T + 1) - 2
        term2 = m - (trigger * k)
        print((term1 + term2) % MOD)
