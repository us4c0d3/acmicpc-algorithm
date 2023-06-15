#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, m;
int dp[10][1<<10];
int check[10];

int solve(int r, int state) {
    if(r == n) return 0;

    int& ret = dp[r][state];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << m); j++) {
            if(j & check[r]) continue;
            int k;
            for(k = 0; k < m; k++) {
                if(j & (1 << k)) {
                    // 왼
                    if (k > 0 && j & (1 << (k - 1))) break;
                    
                    // 오
                    if(k < m - 1 && j & (1 << (k + 1))) break;

                    // 왼위
                    if(k > 0 && state & (1 << (k - 1))) break;

                    // 오위
                    if(k < m - 1 && state & (1 << (k + 1))) break;
                }
            }

            if(k == m) ret = max(ret, solve(r + 1, j) + __builtin_popcount(j));
        }
    }

    return ret;
}

int main() {
    fastio;
    int c;
    cin >> c;

    while(c--) {
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        memset(check, 0, sizeof(check));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char t;
                cin >> t;
                if(t == 'x') check[i] |= (1 << j);
            }
        }

        cout << solve(0, 0) << endl;
    }

    return 0;
}