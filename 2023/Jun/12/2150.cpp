// https://www.acmicpc.net/problem/2150
// Strongly Connected Component
// Kosaraju's Algorithm
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int v, e;
vector<int> adj[10001], rev[10001];
vector<vector<int>> scc;
bool visited[10001], rev_visited[10001];
bool check[10001];
stack<int> st;

void dfs(int cur) {
    visited[cur] = true;
    for(int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(!visited[next]) {
            dfs(next);
        }
    }
    st.push(cur);
}

void rev_dfs(int cur, vector<int>& tmp) {
    rev_visited[cur] = true;
    tmp.push_back(cur); check[cur] = true;
    for(int i = 0; i < rev[cur].size(); i++) {
        int next = rev[cur][i];
        if(!rev_visited[next]) {
            rev_dfs(next, tmp);
        }
    }
}

int main() {
    fastio;
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    for(int i = 1; i <= v; i++) {
        sort(adj[i].begin(), adj[i].end());
        sort(rev[i].begin(), rev[i].end());
    }

    for(int i = 1; i <= v; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    while(!st.empty()) {
        int cur = st.top(); st.pop();
        if(!rev_visited[cur]) {
            vector<int> temp;
            rev_dfs(cur, temp);
            sort(temp.begin(), temp.end());
            scc.push_back(temp);
        }
    }
    for(int i = 1; i <= v; i++) {
        if(!check[i]) {
            vector<int> temp;
            temp.push_back(i);
            scc.push_back(temp);
        }
    }
    sort(scc.begin(), scc.end());

    cout << scc.size() << endl;
    for(auto &i : scc) {
        for(auto &j : i) {
            cout << j << " ";
        }
        cout << -1 << endl;
    }

    return 0;
}