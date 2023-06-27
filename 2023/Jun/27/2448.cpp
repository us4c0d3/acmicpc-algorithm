#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

char board[3072][6144];

vector<string> triangle = {
    "  *  ",
    " * * ",
    "*****"
};

void printTri(int x, int y) {
    board[x][y] = '*';
    board[x + 1][y - 1] = '*';
    board[x + 1][y + 1] = '*';
    for(int i = 0; i < 5; i++) {
        board[x + 2][y - 2 + i] = '*';
    }
}

void solve(int x, int y, int n) {
    if(n == 3) {
        printTri(x, y);
        return;
    }

    solve(x, y, n / 2);
    solve(x + n / 2, y - n / 2, n / 2);
    solve(x + n / 2, y + n / 2, n / 2);
}

void printBoard(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2 * n - 1; j++) {
            if(board[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
}

int main() {
    fastio;
    int n;
    cin >> n;
    solve(0, n - 1, n);
    printBoard(n);
    return 0;
}