#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int arr[2001];
bool dp[2001][2001];
int n, m;
int s, e;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n-1; i++) {
        dp[i][i] = true;
        if(arr[i] == arr[i+1]) dp[i][i+1] = true;
        else dp[i][i+1] = false;
    }
    dp[n][n] = true;

    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= n - i + 1; j++) {
            if(arr[j] == arr[j+i-1] && dp[j+1][j+i-2]) dp[j][j+i-1] = true;
            else dp[j][j+i-1] = false;
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << dp[s][e] << endl;
    }
}


int main() {
    fastio;
    solve();
    return 0;
}
