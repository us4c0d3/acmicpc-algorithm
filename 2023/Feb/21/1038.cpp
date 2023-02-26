#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

#define ROW 11
#define COL 10

int cnt[ROW][COL];
ll sum[ROW][COL];

void set_cnt() {
    for(int i = 0; i < COL; i++) {
        cnt[1][i] = 1;
    }

    for(int i = 2; i < ROW; i++) {
        for(int j = i - 1; j < COL; j++) {
            cnt[i][j] = cnt[i - 1][j - 1] + cnt[i][j - 1];
        }
    }
}

bool promising(ll n) {
    if(n / 10 == 0) return true;
    ll prev = n % 10;
    n /= 10;
    while(n) {
        if(prev >= n % 10) return false;
        prev = n % 10;
        n /= 10;
    }
    return true;
}

pii get_pos(int n) {
    int i, j;
    for(i = 0; i < COL; i++) {
        sum[1][i] = i;
    }
    for(i = 2; i < ROW; i++) {
        sum[i][i - 1] = sum[i - 1][COL - 1] + 1;
        for(j = i; j < COL; j++) {
            sum[i][j] = sum[i][j - 1] + cnt[i][j];
            if(sum[i][j] >= n) break;
        }
        if(sum[i][j] >= n) break;
    }
    return {i, j};
}

void solve(pii pos, int n) {
    int i = pos.first - 1;
    int j = pos.second;
    ll t = pow(10, i) * j;
    int count = 0;
    while(1) {
        if(promising(t)) {
            count++;
        }
        if(count == n || n == 0) break;
        t++;
    }
    cout << t << endl;
}

int main() {
    fastio;
    set_cnt();

    int n;
    cin >> n;

    if(n <= 10) {
        cout << n << endl;
    } else if(n > 1022) {
        cout << -1 << endl;
    } else if(n == 1022) {
        cout << 9876543210 << endl;
    } else {
        pii pos = get_pos(n);
        n -= sum[pos.first][pos.second - 1];
        solve(pos, n);
    }
    return 0;
}