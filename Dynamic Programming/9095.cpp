//https://www.acmicpc.net/problem/9095
//Dynamic Programming
#include <stdio.h>

int memo[11] = {0, 1, 2, 4};

int ans(int x) {
	if(memo[x] != 0) return memo[x];
	return memo[x] = ans(x-1) + ans(x-2) + ans(x-3);
}

int main() {
	int t, n;
	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", ans(n));
	}

	return 0;
}
