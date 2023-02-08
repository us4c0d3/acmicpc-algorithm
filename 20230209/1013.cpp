#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

void solve() {
    int state[8][2] = {
        {1, 2},     //s0
        {-1, 0},    //s1
        {3, -1},    //s2
        {4, -1},    //s3
        {4, 5},     //s4
        {1, 6},     //s5
        {7, 6},     //s6
        {4, 0}      //s7
    };
    int current = 0;
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(current == -1) break;
        current = state[current][s[i] - '0'];
    }

    if(current == 0 || current == 5 || current == 6) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    fastio;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}