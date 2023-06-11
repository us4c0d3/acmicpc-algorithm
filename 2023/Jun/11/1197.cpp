#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, m;
int res = 0;
vector<pii> adj[10001];
int visited[10001];

int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<pii> pq;
    pq.push({-0, 1}); // cost, cur

    while(!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        if(visited[cur]) continue;
        res -= cost;
        visited[cur] = 1;
        for(int i = 0; i < adj[cur].size(); i++) {  // 방문한 노드에 연결된 간선 추가
            auto [next, ncost] = adj[cur][i];
            pq.push({-ncost, next});
        }
    }

    cout << res << endl;

    return 0;
}