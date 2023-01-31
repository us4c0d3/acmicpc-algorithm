//https://www.acmicpc.net/problem/1935
//Stack
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  int n;
  int num[26] = {0, };
  double tmp1, tmp2;
  string postfix;
  cin >> n >> postfix;
  for(int i = 0; i < n; i++) {
    cin >> num[i];
  }

  stack<double> cal;
  for(int i = 0; i < postfix.length(); i++) {
    switch(postfix[i]) {
      case '+':
        tmp2 = cal.top();
        cal.pop();
        tmp1 = cal. top();
        cal.pop();
        tmp1 += tmp2;
        cal. push(tmp1);
        break;
      case '-':
        tmp2 = cal.top();
        cal.pop();
        tmp1 = cal. top();
        cal.pop();
        tmp1 -= tmp2;
        cal. push(tmp1);
        break;
      case '*':
        tmp2 = cal.top();
        cal.pop();
        tmp1 = cal. top();
        cal.pop();
        tmp1 *= tmp2;
        cal. push(tmp1);
        break;
      case '/':
        tmp2 = cal.top();
        cal.pop();
        tmp1 = cal. top();
        cal.pop();
        tmp1 /= tmp2;
        cal. push(tmp1);
        break;
      default:
        cal.push(num[postfix[i] - 'A']);
        break;
    }
  }

  cout<<fixed;
  cout.precision(2);
  cout << cal.top() << endl;

  return 0;
}