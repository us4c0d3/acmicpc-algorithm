#include <iostream>
#include <algorithm>

using namespace std;

char board[50][50];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int cnt = 0;
            int k = 0;
            while(++k) {
                if(i + k >= n || j + k >= m) break;
                if(board[i][j] == board[i][j + k] && board[i][j] == board[i + k][j] && board[i][j] == board[i + k][j + k]) {
                    cnt = max(cnt, k);
                }
            }
            res = max(res, cnt + 1);
        }
    }
    
    cout << res * res << endl;
    return 0;
}