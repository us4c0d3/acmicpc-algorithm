//https://www.acmicpc.net/problem/1106
//Dynamic Programming
#include <iostream>

using namespace std;

int price[20][2];
int res[1001];

int Result(int people, int city) {
  int min = 100 * 1000;
  int sum = 0;
  if(people <= 0) {
    return 0;
  } else if(res[people] != 0) {
    return res[people];
  } else {
    for(int i = 0; i < city; i++) {
      sum = Result(people - price[i][1], city) + price[i][0];
      min = min < sum ? min : sum;
    }

    return res[people] = min;
  }
}


int main() {
  int c, n;
  cin >> c >> n;

  for(int i = 0; i < n; i++) {
    cin >> price[i][0] >> price[i][1];
  }

  cout << Result(c, n) << '\n';
}