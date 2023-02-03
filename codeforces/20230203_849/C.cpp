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
    for(int i = 0; i < n; i++) {
        int k;
        string s;
        cin >> k >> s;
        while(1) {
            if(s[0] != s[k - 1]) {
                k -= 2;
                s = s.substr(1, k);
            } else {
                break;
            }
        }
        cout << k << endl;
    }

    return 0;
}