//https://www.acmicpc.net/problem/11866
//Queue
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  queue<int> circle;
  

  for(int i = 1; i <= n; i++) {
    circle.push(i);
  }

  int i = 0, j = 0;

  cout << "<";
  while(!circle.empty()) {
    i++;
    if(i % k == 0) {
      cout << circle.front();
      j++;
      circle.pop();
      if(j != n) cout << ", ";
      continue;
    }

    circle.push(circle.front());
    circle.pop();
  }
  cout << ">" << endl;
  
  return 0;
}