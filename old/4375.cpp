//https://www.acmicpc.net/problem/4375
//Brute Force
#include <cstdio>

int main() {
  int n;
  while(scanf("%d", &n) != EOF) {
    int num = 0;
    for(int i = 1; i <= n; i++) {
      num = (num * 10 + 1) % n;
      if(num == 0) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}