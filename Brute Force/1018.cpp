//https://www.acmicpc.net/problem/1018
//Brute Force
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string W_first[8] = {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW"
};

string B_first[8] = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB"
};

string board[50];

int W_First_Count(int x, int y) {
  int cnt = 0;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(board[x+i][y+j] != W_first[i][j]) cnt++;
    }
  }

  return cnt;
}

int B_First_Count(int x, int y) {
  int cnt = 0;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(board[x+i][y+j] != B_first[i][j]) cnt++;
    }
  }

  return cnt;
}


int main() {
  int N, M;
  int res = 123123;
  int tmp;
  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    cin >> board[i];
  }

  for(int i = 0; i + 8 <= N; i++) {
    for(int j = 0; j + 8 <= M; j++) {
      tmp = min(W_First_Count(i, j), B_First_Count(i, j));
      if(tmp < res) res = tmp;
    }
  }

  cout << res << '\n';

  return 0;
}