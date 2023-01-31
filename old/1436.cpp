//https://www.acmicpc.net/problem/1436
//Brute Force
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  int i = 0;
  int devil = 665;
  string str;
  cin >> n;

  while(1) {
    devil++;
    str = to_string(devil);
    if(str.find("666") != string::npos) {
      i++;
    }

    if(i == n) {
      cout << devil << '\n';
      break;
    }

  }

  return 0;
}