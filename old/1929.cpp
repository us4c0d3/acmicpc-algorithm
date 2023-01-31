//https://www.acmicpc.net/problem/1929
//Math
#include <iostream>

using namespace std;

bool isPrime[1000001];

void Eratos() {
  for(int i = 2; i < 1000001; i++) {
    isPrime[i] = true;
  }

  for(int i = 2; i*i <= 1000000; i++) {
    if(isPrime[i]) {
      for(int j = i*i; j <= 1000000; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  Eratos();
  for(int i = m; i <= n; i++) {
    if(isPrime[i]) cout << i << '\n';
  }
  
}