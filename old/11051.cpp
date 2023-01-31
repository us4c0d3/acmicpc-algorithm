//https://www.acmicpc.net/problem/11051
//Dynamic Programming
#include <iostream>
#define MAX 1001
using namespace std;

int arr[MAX][MAX] = {{1}, {1, 1}, {1, 2, 1}};

int Comb(int a, int b) {
  if(a == b || b == 0) return arr[a][b] = 1;
  if(arr[a][b] != 0) return arr[a][b];
  return arr[a][b] = (Comb(a-1, b) + Comb(a-1, b-1)) % 10007;
}

int main() {
  int n, m;
  cin >> n >> m;

  int res = Comb(n, m);
  cout << res << '\n';
}