#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, cnt, d;
int root;
vector<int> v[51];

void dfs(int cur) {
    if(d == cur) return;
    
    if(v[cur].size() == 0 || (v[cur].size() == 1 && v[cur][0] == d)) cnt++;
    else {
        for(int i = 0; i < v[cur].size(); i++) {
            if(v[cur][i] != d) {
                dfs(v[cur][i]);
            }
        }
    }
}

int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if(parent == -1) root = i;
        else v[parent].push_back(i);
    }

    cin >> d;
    dfs(root);
    cout << cnt << endl;
    
    return 0;
}