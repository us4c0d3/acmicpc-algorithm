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
    set<string> s;
    int n, m;
    int res = 0;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        s.insert(t);
    }
    for(int i = 0; i < m; i++) {
        string t;
        cin >> t;
        if(s.find(t) != s.end()) res++;
    }
    cout << res << endl;
    return 0;
}