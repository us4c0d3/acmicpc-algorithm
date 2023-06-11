#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

string a, b;
int dp[1001][1001];

int main() {
    fastio;
    cin >> a >> b;

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(a.at(i) == b.at(j)) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout << dp[a.size()][b.size()] << endl;

    return 0;
}