//https://www.acmicpc.net/problem/3052
//Math
#include <stdio.h>

int main(void) {
  int arr[10];
  for(int i = 0; i < 10; i++) {
    scanf("%d", &arr[i]);
    arr[i] %= 42;
  }

  int cnt = 0;
  int rem[42] = {0, };
  for(int i = 0; i < 10; i++) {
    rem[arr[i]] = 1;
  }
  for(int i = 0; i < 42; i++) {
    if(rem[i]) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}