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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int s = 0;
    for(int i = 0; i < n; i++) s += a[i] * b[n - i - 1];
    cout << s << endl;
    return 0;
}