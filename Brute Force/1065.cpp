//https://www.acmicpc.net/problem/1065
//Brute Force
#include <iostream>

using namespace std;

int main() {
  int n, cnt = 99;
  int tmpa, tmpb, tmpc, tmp;
  cin >> n;
  if(n < 100) {
    cout << n << '\n';
  } else {
    for(int i = 100; i <= n; i++) {
      tmpa = i/100;
      tmpb = (i/10)%10;
      tmpc = i%10;
      if(tmpb - tmpa == tmpc - tmpb) {
        cnt++; 
      }
    }
    cout << cnt << '\n';
  }

  return 0;
}