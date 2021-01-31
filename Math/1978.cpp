//https://www.acmicpc.net/problem/1978
//Math
#include <iostream>

using namespace std;

bool isPrime[1001];

void Eratos() {
  for(int i = 2; i < 1001; i++) {
    isPrime[i] = true;
  }

  for(int i = 2; i*i <= 1000; i++) {
    if(isPrime[i]) {
      for(int j = i*i; j <= 1000; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  int n, tmp;
  int cnt = 0;
  cin >> n;
  Eratos();
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    if(isPrime[tmp]) cnt++;
  }
  cout << cnt << '\n';
}