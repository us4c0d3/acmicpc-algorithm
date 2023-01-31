//https://www.acmicpc.net/problem/2581
//Math
#include <iostream>

using namespace std;

bool prime[10001] = {false};

void Eratos() {
  for(int i = 2; i < 10001; i++) {
    prime[i] = true;
  }

  for(int i = 2; i*i <= 10000; i++) {
    if(prime[i]) {
      for(int j = i*i; j <= 10000; j += i) {
        prime[j] = false;
      }
    }
  }
}

int main() {
  int m, n;
  cin >> m >> n;

  Eratos();

  int sum = 0;
  int tmp;
  for(int i = m; i <= n; i++) {
    if(prime[i]) {
      if(sum == 0) tmp = i;
      sum += i;
    }
  }

  if(sum == 0) {
    cout << -1 << '\n';
  } else {
    cout << sum << '\n' << tmp << '\n';
  }
}