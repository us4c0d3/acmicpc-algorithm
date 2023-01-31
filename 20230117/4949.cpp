#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while(1) {
        string temp;
        getline(cin, temp);
        if(temp.length() && temp[0] == '.') break;

        stack<char> s;
        bool res = true;
       
        for(int i = 0; i < temp.length(); i++) {
            if(temp[i] == '(' || temp[i] == '[')
                s.push(temp[i]);
            else if(temp[i] == ')') {
                if(!s.empty() && s.top() == '(') s.pop();
                else {
                    res = false;
                    break;    
                }
            } else if(temp[i] == ']') {
                if(!s.empty() && s.top() == '[') s.pop();
                else {
                    res = false;
                    break;    
                }
            }
        }
        if(res && s.empty()) cout << "yes\n";
        else cout << "no\n";
    } 

    return 0;
}