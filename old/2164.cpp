//https://www.acmicpc.net/problem/2164
//Queue
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, tmp;
  cin >> n;

  queue<int> card;

  for(int i = 1; i <= n; i++) {
    card.push(i);
  }

  while(1) {
    if(card.front() == card.back()) break;

    card.pop();
    tmp = card.front();
    card.pop();
    card.push(tmp);
  }

  cout << card.front() << endl;
  return 0;
}