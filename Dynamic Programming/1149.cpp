//noj.am/1149
//Dynamic Programming
#include <stdio.h>

int min(int a, int b) {return a<b ? a:b;}

int main() {
  int n, i, j;
  scanf("%d", &n);
  int p[1000][3];
  int rgb[1000][3];

  for(i = 0; i < n; i++) {
    for(j = 0; j < 3; j++) {
      scanf("%d", &rgb[i][j]);
    }
  }

  for(i = 0; i < 3; i++) {
    p[0][i] = rgb[0][i];
  }

  for(i = 1; i < n; i++) {
    p[i][0] = min(p[i-1][1], p[i-1][2]) + rgb[i][0];
    p[i][1] = min(p[i-1][0], p[i-1][2]) + rgb[i][1];
    p[i][2] = min(p[i-1][0], p[i-1][1]) + rgb[i][2];
  }

  printf("%d\n", min(min(p[n-1][0], p[n-1][1]), p[n-1][2]));

  return 0;
}