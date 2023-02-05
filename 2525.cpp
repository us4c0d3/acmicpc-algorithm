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
    int h, m;
    int min;
    cin >> h >> m;
    cin >> min;
    m += min;
    while(m >= 60) {
        m -= 60;
        h += 1;
    }
    while(h >= 24) {
        h -= 24;
    }
    
    cout << h << ' ' << m << endl;

    return 0;
}