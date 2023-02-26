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
    int n, num = 64;
    vector<int> v;
    cin >> n;
    v.push_back(64);

    while(num > n) {
        int min = v[0];
        int min_idx = 0;
        for(int i = 0; i < v.size(); i++) {
            if(min > v[i]) {
                min = v[i];
                min_idx = i;
            }
        }
        v.erase(v.begin() + min_idx);
        v.push_back(min / 2);
        num -= min / 2;
        if(num < n) {
            v.push_back(min / 2);
            num += min / 2;
        }
    }

    if(num == n) cout << v.size() << endl;
    else cout << -1 << endl;

    return 0;
}