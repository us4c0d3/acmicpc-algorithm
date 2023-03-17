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
    int s;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> s;

    for(int i = 0; i < n - 1; i++) {
        int max = v[i];
        int idx = i;
        for(int j = i + 1; j < n; j++) {
            if(s - (j - i) >= 0) {
                if(max < v[j]) {
                    max = v[j];
                    idx = j;
                }
            }
        }
        for(int j = idx; j > i; j--) {
            swap(v[j], v[j - 1]);
        }
        s -= (idx - i);
        if(!s) break;
    }
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}