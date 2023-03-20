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

void dfs(int num, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = num; i <= n; i++) {
        if(visited[i]) continue;
        arr[cnt] = i;
        visited[i] = true;
        dfs(i+1, cnt+1);
        visited[i] = false;
    }
}

int main() {
    fastio;
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}