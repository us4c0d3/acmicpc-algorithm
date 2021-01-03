//noj.am/10726
//Dynamic Programming
#include <stdio.h>

int memo[1001] = {1, 1, 2};


int fibo(int i) {
	if(memo[i] != 0) {
    return memo[i];
  } else {
    return memo[i] = (fibo(i-1) + fibo(i-2)) % 10007;
  }
}	

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", fibo(n));

	return 0;
}

