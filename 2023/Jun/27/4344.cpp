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
    int c;
    cin >> c;
    cout.precision(3);
    cout << fixed;
    while(c--) {
        int n;
        cin >> n;
        vector<int> v;
        double sum = 0, avg, cnt = 0;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            sum += tmp;
            v.push_back(tmp);
        }
        avg = (double)sum / n;
        for(int i = 0; i < n; i++) {
            if(v[i] > avg) cnt++;
        }
        cout << cnt / n * 100 << '%' << endl;
    }
    return 0;
}