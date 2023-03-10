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
    int t, n;
    cin >> t;
    int x1, y1, x2, y2;
    int x, y, r;

    for(int i = 0; i < t; i++) {
        int enter = 0;
        int exit = 0;

        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> x >> y >> r;
            int d1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
            int d2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
            if(d1 < r * r && d2 > r * r) enter++;
            if(d1 > r * r && d2 < r * r) exit++;
        }
        
        cout << enter + exit << endl;
    }
    return 0;
}