#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, m;
int arr[9];

void dfs(int num, int x) {
    if(x == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = num; i <= n; i++) {
        arr[x] = i;
        dfs(i, x + 1);
    }
}

int main() {
    fastio;
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}