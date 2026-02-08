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
        int k;
        ll sum = 0;
        ll m = INT_LEAST32_MAX;
        int minus = 0, zeros = 0;
        cin >> k;
        for(int j = 0; j < k; j++) {
            ll num;
            cin >> num;
            if(num < 0) {
                sum += -1 * num;
                m = min(m, -1 * num);
                minus += 1;
            } else if(num == 0) {
                zeros += 1;
                m = min(m, num);
            } else {
                sum += num;
                m = min(m, num);
            }
        }
        if(minus % 2 == 0 || zeros != 0) {
            cout << sum << endl;
        } else {
            cout << sum - (2 * m) << endl;
        }
        
    }

    return 0;
}