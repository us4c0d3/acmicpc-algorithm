#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

vector<vector<int>> a(51, vector<int> (51, 0));
vector<vector<int>> b(51, vector<int> (51, 0));
vector<vector<bool>> chk(51, vector<bool> (51, false));


void change(int n, int m) {
    for(int i = n; i < n+3; i++) {
        for(int j = m; j < m+3; j++) {
            chk[i][j] = !chk[i][j];
        }
    }
}

int main() {
    fastio;
    int n, m;
    int res = 0;
    char d;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> d;
            a[i][j] = d - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> d;
            b[i][j] = d - '0';
            if(a[i][j] != b[i][j]) chk[i][j] = true;
        }
    }

    if(n < 3 || m < 3) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(chk[i][j]) {
                    res = -1;
                    break;
                }
            }
        }
    } else {
        for(int i = 0; i <= n-3; i++) {
            for(int j = 0; j <= m-3; j++) {
                if(chk[i][j]) {
                    change(i, j);
                    res++;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(res == -1) break;
        for(int j = 0; j < m; j++) {
            if(chk[i][j]) {
                res = -1;
                break;
            }
        }
    }

    cout << res << endl;
    return 0;
}