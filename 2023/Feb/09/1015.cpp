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

    vector<pii> a;
    int p[50];

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back({t, i});
    }
    stable_sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        p[a[i].second] = i;
    }

    for(int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }

    cout << endl;
    return 0;
}