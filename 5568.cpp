#include <stdio.h>

int ans[31][31];

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < 31; i++) {
		ans[i][i] = 1;
		ans[i][0] = 1;
		for(int j = 1; j <= i-1; j++) {
			ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
		}
	}

	for(int k = 0; k < n; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", ans[b][a]);
	}

	return 0;
}
