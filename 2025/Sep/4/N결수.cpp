#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int main() {
    fastio;
    int n, k;
    ll res = 0;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        int tmp = i;
        while(tmp) {
            tmp /= 10;
            res *= 10;
        }
        res = (res + i) % k;
    }
    
    cout << res << endl;
    return 0;
}