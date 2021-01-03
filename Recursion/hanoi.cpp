//noj.am/1914
//Recursion
#include <stdio.h>

int hanoi(int amount, int start, int end);

int main() {
	int k;
	scanf("%d", &k);
	printf("%d\n", (2<<(k-1))-1);
	hanoi(k, 1, 3);
}

int hanoi(int amount, int start, int end) {
	if (amount <= 1) {
		printf("%d %d\n", start, end);
		return 0;
	}
	
	hanoi(amount - 1, start, 6-(start+end));
	
	printf("%d %d\n", start, end);
	
	hanoi(amount - 1, 6 - (start+end), end);
}


//i cant understand it now fuck