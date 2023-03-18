#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

#define MAX 9

int n, m;
int arr[MAX];
bool visited[MAX];

void init() {
    for(int i = 0; i < MAX; i++) {
        visited[i] = false;
        arr[i] = 0;
    }
}

void dfs(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        arr[cnt] = i;
        dfs(cnt+1);
        visited[i] = false;
    }
}

int main() {
    fastio;
    cin >> n >> m;
    dfs(0);
    return 0;
}