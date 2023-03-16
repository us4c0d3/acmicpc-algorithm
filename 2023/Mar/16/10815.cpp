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
    set<int> s;
    int n, m;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        s.insert(t);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(s.find(t) != s.end()) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;
    return 0;
}