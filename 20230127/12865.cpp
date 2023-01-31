// knapsack problem
// https://www.acmicpc.net/problem/12865
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define MAX_SIZE 101
#define MAX_WEIGHT 100001

int profit[MAX_SIZE][MAX_WEIGHT];

int main() {
    fastio;
    int n, k;
    int w, v;
    vector<pii>vv;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> w >> v;
        vv.push_back({w, v});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            int curweight = vv[i - 1].first;
            int curvalue = vv[i - 1].second;

            if(curweight > j) {
                profit[i][j] = profit[i - 1][j];
            } else { // curweight <= j
                profit[i][j] = max(profit[i - 1][j], curvalue + profit[i - 1][j - curweight]);
            }
        }
    }

    cout << profit[n][k] << endl;
    return 0;
}