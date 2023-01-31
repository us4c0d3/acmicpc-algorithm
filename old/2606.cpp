//https://www.acmicpc.net/problem/2606
//Graph
#include <iostream>

using namespace std;

int com, v;
bool infected[101] = {false, };
bool edge[1001][1001] = {false, };

void dfs(int x) {
  infected[x] = true;
  for(int i = 1; i <= com; i++) {
    if(edge[x][i] && !infected[i]) dfs(i);
  }
}

int main() {
  cin >> com >> v;
  for(int i = 0; i < v; i++) {
    int a, b;
    cin >> a >> b;
    edge[a][b] = true;
    edge[b][a] = true;
  }

  dfs(1);

  int cnt = -1;
  for(int i = 1; i <= com; i++) {
    if(infected[i]) cnt++;
  }

  cout << cnt << '\n';
}