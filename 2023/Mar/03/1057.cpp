#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int main() {
    fastio;
    int n, k, l;
    int cnt = 0;
    cin >> n >> k >> l;

    while(k != l) {
        k = (k + 1) / 2;
        l = (l + 1) / 2;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}