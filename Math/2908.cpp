//https://www.acmicpc.net/problem/2908
//Math
#include <stdio.h>

int Reverse(int x) {
  int a, b, c;
  a = x / 100;
  b = (x / 10) % 10;
  c = x % 10;
  x = 100 * c + 10 * b + a;
  return x;
}

int main(void) {
  int a, b;
  scanf("%d%d", &a, &b);

  int rev_a, rev_b;
  rev_a = Reverse(a);
  rev_b = Reverse(b);
  printf("%d\n", rev_a > rev_b ? rev_a : rev_b);
  return 0;
}