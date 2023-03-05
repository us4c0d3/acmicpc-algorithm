#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, cnt, d;
int root = -1;
vector<int> v[51];
bool visited[51];

void dfs(int cur) {
    if(visited[cur]) return;

    visited[cur] = true;
    if(v[cur].size() == 0 || (v[cur].size() == 1 && v[cur][0] == d)) cnt++;

    for(int i = 0; i < v[cur].size(); i++) {
        if(v[cur][i] != d) {
            dfs(v[cur][i]);
        }
    }
}

int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t == -1) root = i;
        else v[t].push_back(i);
    }

    cin >> d;
    if(d == root) cout << 0 << endl;
    else {
        dfs(root);
    }
    cout << cnt << endl;
    
    return 0;
}