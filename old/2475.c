#include <stdio.h>

int main() {
	int tmp;
	int sum = 0;
	for(int i = 0; i < 5; i++ ) {
		scanf("%d", &tmp);
		sum += tmp*tmp;
	}
	printf("%d\n", sum%10);
	return 0;
}
