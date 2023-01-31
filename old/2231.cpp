//https://www.acmicpc.net/problem/2231
//Brute Force
#include <stdio.h>

int main(void) {
  int n, temp, jari = 0;
  int min, sum = 0;
  
  scanf("%d", &n);
  temp = n;
  
  while(temp!=0) {
    temp = temp/10;
    jari++;
  }

  min = n - (9*jari);
  for(int i = 0; i < 9*jari ; i++) {
    temp = min;
    sum = temp;
    for(int j = 0; j < jari; j++) {
      sum = sum + temp%10;
      temp = temp/10;
    }

    if(sum == n) {
      printf("%d", min);
      return 0;
    }
    min++;
  }

  printf("0");
  return 0;
}