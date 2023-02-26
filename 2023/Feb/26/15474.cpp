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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int x, y;
    if(n % a == 0) x = b * (n / a);
    else x = b * (n / a + 1);
    if(n % c == 0) y = d * (n / c);
    else y = d * (n / c + 1);
    cout << min(x, y) << endl;
    return 0;
}