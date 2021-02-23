//https://www.acmicpc.net/problem/2309
//Brute Force
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  int num1 = *(int *)a;
  int num2 = *(int *)b;
  if(num1 > num2) return 1;
  if(num1 < num2) return -1;
  return 0;
}

int main(void) {
  int arr[9] = {0, };
  int sum = 0;
  for(int i = 0; i < 9; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }

  for(int i = 0; i < 8; i++) {
    for(int j = i + 1; j < 9; j++) {
      if(sum - arr[i] - arr[j] == 100) {
        arr[i] = -1;
        arr[j] = -1;
        break;
      }
    }
    if(arr[i] == -1) break;
  }
  qsort(arr, 9, sizeof(int), compare);

  for(int i = 2; i < 9; i++) {
    printf("%d\n", arr[i]);
  }
  
  return 0;
}