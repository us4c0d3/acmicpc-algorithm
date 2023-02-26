#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main() {
    int res = 0;
    string str, num;
    bool minus = false;
    cin >> str;


    for(int i = 0; i <= str.length(); i++) {
        if(str[i] == '-' || str[i] == '+' || i == str.length()) {
            if(minus) res -= stoi(num);
            else res += stoi(num);
            num = "";
        } else {
            num += str[i];
        }

        if(str[i] == '-') minus = true;
    }
    cout << res << endl;
    return 0;
}