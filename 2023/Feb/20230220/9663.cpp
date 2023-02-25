#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int queen_col[15];
int n;
int cnt = 0;

bool promising(int row) {
    for(int i = 0; i < row; i++) {
        if(queen_col[i] == queen_col[row] || row - i == abs(queen_col[i] - queen_col[row])) return false;
    }

    return true;
}

void nqueen(int row) {
    if(row == n) {
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++) {
        queen_col[row] = i;
        if(promising(row)) nqueen(row + 1);
    }
}

int main() {
    fastio;
    cin >> n;

    nqueen(0);
    cout << cnt << endl;
    
    return 0;
}