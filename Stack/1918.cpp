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
  int now_rank = 0, i = 0;
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

      now_rank = 0;
      if(!oper.empty()) now_rank = Rank(oper.top());


    } else if(now_rank < Rank(infix[i])) {
      oper.push(infix[i]);
      now_rank = Rank(oper.top());


    } else {
      while(!oper.empty()) {
        postfix += oper.top();
        oper.pop();
      }
      oper.push(infix[i]);

      now_rank = Rank(oper.top());
    }
  }

  while(!oper.empty()) {
    postfix += oper.top();
    oper.pop();
  }

  cout << postfix << endl;
  return 0;
}

//what the segfault__