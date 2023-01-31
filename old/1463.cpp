//https://www.acmicpc.net/problem/1463
//Dynamic Programming
#include <stdio.h>

int min(int x, int y) {return x<y?x:y;}
int ans[1000001] = {0, 0};

int main() {
	int n;
	scanf("%d", &n);

	for(int i = 2; i <= n; i++) {
		ans[i] = ans[i-1] + 1; //rule 3
		if(i % 3 == 0) {
			ans[i] = min(ans[i], ans[i/3] + 1); //rule 1
		}
		if (i % 2 == 0) {
			ans[i] = min(ans[i], ans[i/2] + 1); //rule 2
		}
	}

	printf("%d\n", ans[n]);

	return 0;
}

