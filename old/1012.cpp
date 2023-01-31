//https://www.acmicpc.net/problem/1012
//Graph
#include <iostream>

using namespace std;

int m, n, k;
bool visited[51][51] = {false, };
bool graph[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


void init() {
  for(int i = 0; i < 51; i++) {
    for(int j = 0; j < 51; j++) {
      visited[i][j] = false;
      graph[i][j] = false;
    }
  }
}

void dfs(int y, int x) {
  visited[y][x] = true;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(graph[ny][nx] && !visited[ny][nx] && (ny >= 0 && ny < n) && (nx >= 0 && nx < m)) dfs(ny, nx); 
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  
  while(t--) {
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
      int y, x;
      cin >> y >> x;
      graph[x][y] = true;
    }

    int cnt = 0;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(graph[j][i] && !visited[j][i]) {
          cnt++;
          dfs(j, i);
        }
      }
    }

    cout << cnt << '\n';
    init();
  }
}