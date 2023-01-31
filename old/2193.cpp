//https://www.acmicpc.net/problem/2193
//Dynamic Programming
#include <stdio.h>

long long int memo[91] = {0, 1, 1};

long long int fibo(int x) {
	if(memo[x] != 0) return memo[x];
	return memo[x] = fibo(x-1) + fibo(x-2);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", fibo(n));

	return 0;
}
