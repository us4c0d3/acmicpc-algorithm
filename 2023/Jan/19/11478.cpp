#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    set<string>s;
    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        string t;
        for(int j = i; j < str.length(); j++) {
            t += str[j];
            s.insert(t);
        }
    }
    cout << s.size() << '\n';
}