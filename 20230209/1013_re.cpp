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
    int T;
    cin >> T;
    regex re("(100+1+|01)+");

    for(int i = 0; i < T; i++) {
        string s;
        cin >> s;
        cout << (regex_match(s, re) ? "YES" : "NO") << endl;
    }

    return 0;
}