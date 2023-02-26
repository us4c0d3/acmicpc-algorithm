#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

ll a, b, c;

// x^n
ll power(ll x, ll n) {
    if(n == 0) return 1;
    else if(n == 1) return x;

    if(n % 2 != 0) {
        return (power(x, n - 1) * x) % c;
    }

    ll half = (power(x, n / 2)) % c;
    return (half * half) % c;
}

int main() {
    fastio;
    cin >> a >> b >> c;
    cout << power(a, b) % c << endl;
    return 0;
}