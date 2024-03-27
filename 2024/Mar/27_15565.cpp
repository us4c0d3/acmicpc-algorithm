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
    int n, k;
    cin >> n >> k;

    vector<int> idx;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            idx.push_back(i);
        }
    }

    if(idx.size() < k) {
        cout << -1 << endl;
        return 0;
    }

    int res = INT_MAX;
    for(int i = 0; i <= idx.size() - k; i++) {
        res = min(res, idx[i + k - 1] - idx[i] + 1);
    }

    cout << res << endl;
    return 0;
}