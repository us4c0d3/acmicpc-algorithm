//https://www.acmicpc.net/problem/3986
//Stack
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  int n, res = 0;
  string str;

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> str;
    stack<char> word;

    for(int j = 0; j < str.length(); j++) {
      if(!word.empty() && word.top() == str[j]) {
        word.pop();
      } else {
        word.push(str[j]);
      }
    }

    if(word.empty()) res++;
  }

  cout << res << endl;

  return 0;
}