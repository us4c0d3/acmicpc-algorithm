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
    set<int> a, b;
    int n, m;
    int tmp;
    int res = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.insert(t);
    }
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        b.insert(t);
    }

    tmp = 0;
    for(auto& s : a) {
        if(b.find(s) != b.end()) {
            tmp++;
        }
    }
    res += n - tmp;

    tmp = 0;
    for(auto& s : b) {
        if(a.find(s) != a.end()) {
            tmp++;
        }
    }
    res += m - tmp;

    cout << res << endl;
    return 0;
}