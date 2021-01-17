//https://www.acmicpc.net/problem/1918
//Stack
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int Rank(char data) {
  if(data == '(' || data == ')') return -1;
  if(data == '*' || data == '/') return 2;
  if(data == '+' || data == '-') return 1;
  return 0;
}

int main() {
  int now_rank = 0, i = 0, j = 0, temp = 0;
  string infix;
  char postfix[100] = {0, };
  cin >> infix;

  stack<char> oper;

  while(i < infix.length()) {
    if(infix.at(i) >= 'A' && infix.at(i) <= 'Z') {
      postfix[j] = infix.at(i);
      j++;
    } else {
      if(infix.at(i) == '(' || now_rank <= Rank(infix.at(i))) {
        oper.push(infix.at(i));
      } else if(infix.at(i) == ')') {
        while(oper.top() != '(') {
          postfix[j] = oper.top();
          oper.pop();
          j++;
        }
        oper.pop();
        temp += 2;
        now_rank = 0;
        if(!oper.empty()) now_rank = oper.top();
      } else {
        while(!oper.empty()) {
          postfix[j] = oper.top();
          oper.pop();
          j++;
        }
        now_rank = 0;
      }
    }
    i++;
  }
  cout << oper.empty() << endl;
  while(!oper.empty()) {
    postfix[j] = oper.top();
    oper.pop();
    j++;
  }

  for(i = 0; i < infix.length() - temp; i++) {
    cout << postfix[i];
  }
  return 0;
}