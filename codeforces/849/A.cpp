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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char t;
        cin >> t;
        if((t >= 'c' && t <= 'f') || t == 'o' || t == 'r' || t == 's') {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}