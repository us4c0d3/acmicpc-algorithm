<<<<<<< HEAD
//https://www.acmicpc.net/problem/7568
=======
//noj.am/7568
>>>>>>> 326649ecc6bd774a4243e0f0d7142a197e83865d
//Brute Force
#include <stdio.h>

int main() {
  int x[50] = {0, };
  int y[50] = {0, };
  int n, k, i, j;
  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }

  for(i = 0; i < n; i++) {
    k = 1;
    for(j = 0; j < n; j++) {
      if(x[i] < x[j] && y[i] < y[j]) {
        k++;
      }
    }
    printf("%d ", k);
  }

  return 0;
}