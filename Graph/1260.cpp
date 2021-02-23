//https://www.acmicpc.net/problem/1260
//Graph
#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
int graph[1001][1001] = {0, };
bool visited[1001];

void init() {
  for(int i = 0; i <= 1000; i++) visited[i] = false;
  cout << '\n';
}

void dfs(int x) {
  visited[x] = true;
  cout << x << ' ';
  for(int i = 1; i <= n; i++) {
    if(graph[x][i] && !visited[i]) dfs(i);
  }
}

void bfs(int x) {
  queue<int> q;
  visited[x] = true;
  q.push(x);

  while(!q.empty()) {
    int k = q.front();
    visited[k] = true;
    q.pop();
    cout << k << ' ';

    for(int i = 1; i <= n; i++) {
      if(graph[k][i] && !visited[i]) {
        visited[i] = true;
        q.push(i);
      }
    }
  }
}



int main() {
  cin >> n >> m >> v;

  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }

  dfs(v);
  init();
  bfs(v);
  init();
}