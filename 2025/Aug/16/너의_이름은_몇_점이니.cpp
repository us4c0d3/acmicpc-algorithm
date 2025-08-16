#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int main() {
    fastio;
    int n, res = 0;
    string s;
    cin >> n;
    cin >> s;
    for (char c : s) {
		res += c - 'A' + 1;
    }
	cout << res << endl;
    return 0;
}