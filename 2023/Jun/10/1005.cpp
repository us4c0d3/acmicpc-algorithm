#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

void solve() {
    int n, k, w;
    vector<int> v[1001];
    int time[1001] = {0, };
    int inDegree[1001] = {0, };
    int sum[1001] = {0, };
    
    // input
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> time[i];
    }  
    for(int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        inDegree[b]++;
    }
    cin >> w;

    // topological sort
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) q.push(i);
        sum[i] = time[i];
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            inDegree[next]--;
            if(inDegree[next] == 0) q.push(next);
            sum[next] = max(sum[next], sum[cur] + time[next]);
        }
    }

    // output
    cout << sum[w] << endl;
}


int main() {
    fastio;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}