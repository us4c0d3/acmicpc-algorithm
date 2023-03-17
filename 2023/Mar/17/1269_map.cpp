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
    map<int, bool> a;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n+m; i++) {
        int t;
        cin >> t;
        if(a[t] == true) a.erase(t);
        else a[t] = true;
    }

    cout << a.size() << endl;
    return 0;
}