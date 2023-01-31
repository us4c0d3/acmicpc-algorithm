#include <iostream>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    set<int>S;
    set<int>::iterator it;

    for(int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        if(temp.length() == 3) {
            for(int i = 1; i <= 20; i++) {
                S.insert(i);
            }
        } else {
            string sub;
            if(temp[0] == 'a') {
                sub = temp.substr(4, temp.length());
                S.insert(stoi(sub));
            } else if(temp[0] == 'r') {
                sub = temp.substr(6, temp.length());
                S.erase(stoi(sub));
            } else if(temp[0] == 'c') {
                sub = temp.substr(6, temp.length());
                it = S.find(stoi(sub));
                if(it == S.end()) cout << '0' << '\n';
                else cout << '1' << '\n';
            } else if(temp[0] == 't') {
                sub = temp.substr(7, temp.length());
                it = S.find(stoi(sub));
                if(it == S.end()) S.insert(stoi(sub));
                else S.erase(stoi(sub));
            } else if (temp[0] == 'e')
                S.clear();
        }
    }
    return 0;
}