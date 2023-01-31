//https://www.acmicpc.net/problem/11057
//Dynamic Programming
#include <stdio.h>

int memo[1001][10];

int main() {
  int n, i, j, k;
  int sum = 0;
  scanf("%d", &n);
  for(i = 0; i <= 9; i++) memo[1][i] = 1; //한자릿수

  for(i = 2; i <= n; i++) {         //n: 자릿수
    for(j = 0; j <= 9; j++) {       //j: 맨앞자리 숫자
      for(k = j; k <= 9; k++) {     //k: 맨앞자리 숫자 증가
        memo[i][k] += memo[i-1][j];
        memo[i][k] %= 10007;
      }
    }
  }

  for(i = 0; i <= 9; i++) {
    sum += memo[n][i];
  }

  printf("%d\n", sum % 10007);

  return 0;
}