//https://www.acmicpc.net/problem/6603
//Recursion
#include <stdio.h>

int arr[50];
int lotto[6];

void lotto_set(int arr_i, int lotto_i, int x) {
  if(lotto_i == 6) {
    for(int i = 0; i < 6; i++) {
      printf("%d ", lotto[i]);
    }
    printf("\n");
    return;
  }

  for(int i = arr_i; i < x; i++) {
    lotto[lotto_i] = arr[i];
    lotto_set(i + 1, lotto_i + 1, x);
  }
}


int main() {
  int n, i;
  
  while(1) {
    scanf("%d", &n);
    if(n == 0) break;

    for(i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    lotto_set(0, 0, n);
    printf("\n");
  }

  return 0;
}