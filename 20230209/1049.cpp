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
    int n, m;
    int res1, res2, res3;
    int p = INT_MAX;
    int e = INT_MAX;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        p = min(p, a);
        e = min(e, b);
    }
    res1 = (n / 6) * p + (n % 6) * e;
    res2 = (n / 6) * p + p;
    res3 = n * e;
    
    res1 = min(res1, res3);
    cout << min(res1, res2) << endl;
    
    return 0;
}