#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, f;

void solve() {
    int head = n / 100;

    for(int i = 0; i < 100; i++) {
        if((head * 100 + i) % f == 0) {
            printf("%02d\n", i);
            return;
        }
    }
}

int main() {
    scanf("%d %d", &n, &f);
    solve();
    return 0;
}