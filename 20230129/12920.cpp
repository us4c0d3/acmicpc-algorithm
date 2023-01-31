// knapsack problem
// bit mask
// https://www.acmicpc.net/problem/12920
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define MAX_SIZE 2000
#define MAX_WEIGHT 10001

int profit[MAX_SIZE][MAX_WEIGHT];

int main() {
    fastio;
    int n, m;
    int cnt = 0;
    int v, c, k;
    vector<pii>vv;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> v >> c >> k;
        for(int j = 0; k > 0; j++) {
            int tmp = min(k, 1 << j);
            vv.push_back({v * tmp, c * tmp});
            k -= tmp;
            cnt++;
        }
    }

    for(int i = 1; i <= cnt; i++) {
        for(int j = 1; j <= m; j++) {
            int curweight = vv[i - 1].first;
            int curvalue = vv[i - 1].second;

            if(curweight > j) {
                profit[i][j] = profit[i - 1][j];
            } else { // curweight <= j
                profit[i][j] = max(profit[i - 1][j], curvalue + profit[i - 1][j - curweight]);
            }
        }
    }

    cout << profit[cnt][m] << endl;
    return 0;
}