//https://www.acmicpc.net/problem/1918
//Stack
#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

int Rank(char data) {
  if(data == '(') return 3;
  if(data == '*' || data == '/') return 2;
  if(data == '+' || data == '-') return 1;
  if(data == ')') return 0;
}

int main() {
  int now_rank = 0, i = 0, j = 0;
  string infix;
  char postfix[100] = {0, };
  cin >> infix;

  stack<char> oper;


  while(i < infix.length()) {
    if(infix.at(i) >= 'A' && infix.at(i) <= 'Z') {
      postfix[j] = infix.at(i);
      j++;
    } else {
      if(now_rank <= Rank(infix.at(i))) {
        oper.push(infix.at(i));
        now_rank = Rank(infix.at(i));
      } else {
        while(!oper.empty()) {
          now_rank = 0;
          postfix[j] = oper.top();
          oper.pop();
          j++;
        }
      }
    }
    i++;
  }

  for(int k = 0; k < infix.length(); k++) {
    printf("%c", postfix[k]);
  }
  return 0;
}