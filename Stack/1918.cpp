//https://www.acmicpc.net/problem/1918
//Stack
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int Rank(char data) {
  if(data == '*' || data == '/') return 2;
  if(data == '+' || data == '-') return 1;
  return 0;
}

int main() {
  int i = 0;
  string infix;
  string postfix;
  cin >> infix;

  stack<char> oper;

  for(i = 0; i < infix.length(); i++) {
    if(infix[i] >= 'A' && infix[i] <= 'Z') {
      postfix += infix[i];


    } else if (infix[i] == '(') {
      oper.push(infix[i]);


    } else if (infix[i] == ')') {
      while(!oper.empty() && oper.top() != '(') {
        postfix += oper.top();
        oper.pop();
      }
      oper.pop();


    } else if(!oper.empty() && Rank(oper.top()) < Rank(infix[i])) {
      oper.push(infix[i]);


    } else {
      while(!oper.empty()) {
        postfix += oper.top();
        oper.pop();
      }
      oper.push(infix[i]);
    }
  }

  while(!oper.empty()) {
    postfix += oper.top();
    oper.pop();
  }

  cout << postfix << endl;
  return 0;
}

//32% get segfault