//https://www.acmicpc.net/problem/2667
//Graph
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string apt[25];
bool visited[25][25] = {false, };
int n, cnt;
vector<int> ans;

void dfs(int x, int y) {
  visited[x][y] = true;
  cnt++;
  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if((nx >= 0 && nx < n) && (ny >= 0 && ny < n) && apt[nx][ny] == '1' && !visited[nx][ny]) dfs(nx, ny);
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> apt[i];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(apt[i][j] == '1' && !visited[i][j]){
        cnt = 0;
        dfs(i, j);
        ans.push_back(cnt);
      }
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}