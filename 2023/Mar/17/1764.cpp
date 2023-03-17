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
    set<string> listen, see;
    vector<string> res;
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        listen.insert(t);
    }
    for(int i = 0; i < m; i++) {
        string t;
        cin >> t;
        see.insert(t);
    }

    for(auto& s : listen) {
        if(see.find(s) != see.end()) {
            res.push_back(s);
            cnt++;
        }
    }

    cout << cnt << endl;
    for(int i = 0; i < cnt; i++) cout << res[i] << endl;
    return 0;
}