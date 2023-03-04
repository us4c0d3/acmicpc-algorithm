#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int res[10];

void calc(int n, int ten) {
    while(n > 0) {
        res[n % 10] += ten;
        n /= 10;
    }
}

void solve(int A, int B, int ten) {
    while(A % 10 != 0 && A <= B) {
        calc(A, ten);
        A++;
    }
    if(A > B) return;
    while(B % 10 != 9 && A <= B) {
        calc(B, ten);
        B--;
    }

    int cnt = (B / 10) - (A / 10) + 1;
    for(int i = 0; i < 10; i++) {
        res[i] += cnt * ten;
    }
    solve(A / 10, B / 10, ten * 10);
}

int main() {
    fastio;
    int n;
    cin >> n;
    
    solve(1, n, 1);
    for(int i = 0; i < 10; ++i) {
        cout << res[i] << endl;
    }
    return 0;
}