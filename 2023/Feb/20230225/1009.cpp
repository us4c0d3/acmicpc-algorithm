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
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int a, b;
        int res = 1;
        cin >> a >> b;
        for(int j = 0; j < b; j++) {
            res *= a;
            res %= 10;
        }
        if(res == 0) res = 10;
        cout << res << endl;
    }
    return 0;
}