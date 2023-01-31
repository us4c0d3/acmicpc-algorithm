#include <iostream>
#include <queue>

#define MAX_SIZE 100
#define X first
#define Y second
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) 

using namespace std;

int visited[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
string map[MAX_SIZE];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;



int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int xx, yy;
    queue<pair<int, int>> q;

    cin >> N >> M;
   
    for(int i = 0; i < N; i++) {
        cin >> map[i];
    }

    
    q.push({0, 0});
    visited[0][0] = 1;
    dist[0][0] = 1;
    while(!q.empty()) {
        pair<int, int> cur;
        cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            xx = cur.X + dx[i];
            yy = cur.Y + dy[i];

            if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
            if(visited[xx][yy] || map[xx][yy] != '1') continue;

            visited[xx][yy] = 1;
            dist[xx][yy] = dist[cur.X][cur.Y] + 1;
            q.push({xx, yy});
        }
    }

    cout << dist[N - 1][M - 1] << '\n';

    return 0;
}