#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

void cut(int n, int start, int end, vector<string>& v) {
    if(n == 0) return;
    int left = (end - start) / 3;
    for(int i = start + left; i < end - left; i++) {
        v[i] = " ";
    }
    cut(n - 1, start, start + left, v);
    cut(n - 1, end - left, end, v);
}

int main() {
    fastio;
    int n;
    while(cin >> n) {
        vector<string> v;
        for(int i = 0; i < pow(3, n); i++) {
            v.push_back("-");
        }
        cut(n, 0, v.size(), v);
        for(auto& i : v) {
            cout << i;
        }  
        cout << endl;
    }
    return 0;
}