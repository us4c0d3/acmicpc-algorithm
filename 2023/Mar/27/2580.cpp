#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int board[9][9];
vector<pii> blank;
int cnt = 0;
bool found = false;

void input() {
    pii p;
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) {
                cnt++;
                p.first = i;
                p.second = j;
                blank.push_back(p);
            }
        }
    }
}

void print() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(pii p) {
    int x = p.first;
    int y = p.second;
    int thr_x = x / 3;
    int thr_y = y / 3;

    for(int i = 0; i < 9; i++) {
        if(i != y && board[x][i] == board[x][y]) return false;
        if(i != x && board[i][y] == board[x][y]) return false;
    }

    for(int i = thr_x * 3; i < thr_x * 3 + 3; i++) {
        for(int j = thr_y * 3; j < thr_y * 3 + 3; j++) {
            if(i != x && j != y && board[i][j] == board[x][y]) return false;
        }
    }
    return true;
}

void sudoku(int n) {
    if(cnt == n) {
        print();
        found = true;
        return;
    }

    for(int i = 1; i <= 9; i++) {
        board[blank[n].first][blank[n].second] = i;
        if(check(blank[n])) {
            sudoku(n + 1);
            if(found) return;
        }
    }
    board[blank[n].first][blank[n].second] = 0;
    return;
}

int main() {
    fastio;
    input();
    sudoku(0);
    return 0;
}