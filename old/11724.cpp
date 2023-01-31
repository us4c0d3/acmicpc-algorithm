//https://www.acmicpc.net/problem/11724
//Graph
#include <iostream>

using namespace std;

int n, m;
int graph[1001][1001];
bool visited[1001] = {false, };

void dfs(int x) {
  visited[x] = true;
  for(int i = 0; i <= n; i++) {
    if(graph[x][i] && !visited[i]) dfs(i);
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }

  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(visited[i]) continue;
    dfs(i);
    cnt++;
  }

  cout << cnt << '\n';
}