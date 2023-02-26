#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define INF 987654321
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

bool arr[51][51];
bool visited[51][51];
int n, m;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int bfs(int x, int y) {
    int tmp = INF;
    queue<pair<pii, int>> q;
    q.push({{x, y}, 0});
    visited[x][y] = true;

    while(!q.empty()) {
        int xx = q.front().first.first;
        int yy = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        

        for(int i = 0; i < 8; i++) {
            int xxx = xx + dx[i];
            int yyy = yy + dy[i];

            if(xxx < 1 || xxx > n || yyy < 1 || yyy > m) continue;
            if(visited[xxx][yyy]) continue;

            if(arr[xxx][yyy]) return cnt + 1;

            q.push({{xxx, yyy}, cnt + 1});
            visited[xxx][yyy] = true;
        }
    }
    return tmp;
}


int main() {
    fastio;
    int res = -1;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!arr[i][j]) {
                res = max(bfs(i, j), res);
                memset(visited, false, sizeof(visited));
            }
        }
    }

    cout << res << endl;
    return 0;
}