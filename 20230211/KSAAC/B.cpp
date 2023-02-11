#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int main() {
    fastio;
    string s;
    int n, m;
    cin >> n >> m;
    cin >> s;

    if(s.find('A') == string::npos) {
        cout << "NO" << endl;
    } else if(n == m) {
        if(s[n - 2] != 'A' || s[n - 3] != 'A') {
            cout << "NO" << endl;
        }
        else if(s[n - 1] == 'A' || s[n - 1] == 'E' || s[n - 1] == 'I' || s[n - 1] == 'O' || s[n - 1] == 'U') {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << s << endl;
        }
    }

    return 0;
}