#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, m;
vector<int> v[32001];
int indegree[32001];

void solve() {
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }
    cout << endl;
}

int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    solve();
    return 0;
}